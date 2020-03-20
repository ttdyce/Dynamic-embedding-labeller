#include <iostream>
#include <fstream>
#include <sstream> //for std::stringstream
#include <windows.h>
#include <string>

using namespace std;
template <typename T>
class Intercept
{
public:
	Intercept() : t_()
	{
		t_ = -1;
		label = 0;
	}
	Intercept(const T &t) : t_(t)
	{
		label = 0;
	}
	Intercept(const T &t, int l) : t_(t)
	{
		label = l;
	}

	operator T &() { return t_; }
	operator const T &() const { return t_; }
	T t_;
	int label;
};

class StateIntercept
{
	int SIZE;
	Intercept<int> state[];

public:
	StateIntercept(Intercept<int> intercepts[], int length)
	{
		SIZE = length;
		state[length];
		for (int i = 0; i < length; i++)
		{
			state[i] = intercepts[i];
		}

		initStateTraceText();
	}

	Intercept<int> &operator[](int i)
	{
		if (i > SIZE)
		{
			cout << "Index out of bounds" << endl;
			// return first element. Should be unreachable.
			return state[0];
		}

		logCurrentState(state, SIZE);

		return state[i];
	}

	void logCurrentState()
	{
		logCurrentState(state, SIZE);
	}

	void logCurrentState(Intercept<int> state[], int size)
	{
		string currentStateText = "";
		currentStateText += ", [";
		for (int i = 0; i < size; i++)
		{
			string stateValueText = to_string(state[i].t_);
			if (i == 0)
				currentStateText += stateValueText;
			else
				currentStateText += ", " + stateValueText;
		}
		currentStateText += "]";

		logStateTraceText(currentStateText);
	}

	string getCurrentFileName()
	{
		char buffer[MAX_PATH];
		GetModuleFileName(NULL, buffer, MAX_PATH);
		string::size_type pos = string(buffer).find_last_of("\\/");
		// std::cerr << "Got file name: " << string(buffer).substr(pos+1, string(buffer).find_last_of("."));
		return string(buffer).substr(pos + 1, string(buffer).find_last_of("."));
	}

	void initStateTraceText()
	{

		std::stringstream addr;
		addr << &state;

		ifstream f("out-datasetText/logState-" + getCurrentFileName() + "-" + addr.str() + ".json");
		if (f.good())
			return;//file exist, continue logging

		string statesLabelArray = "";
		statesLabelArray += "[";
		for (int i = 0; i < SIZE; i++)
		{
			string label = to_string(state[i].label);
			if (i == 0)
				statesLabelArray += label;
			else
				statesLabelArray += ", " + label;
		}
		statesLabelArray += "]";

		ofstream logFile("out-datasetText/logState-" + getCurrentFileName() + "-" + addr.str() + ".json");
		logFile << "{\"labels\": " << statesLabelArray << ", \"stateTraces\": ["
				<< " ]}";
	}

	//replace the " ]}" with a new element
	void logStateTraceText(string stateText)
	{
		std::stringstream addr;
		addr << &state;

		ifstream in("out-datasetText/logState-" + getCurrentFileName() + "-" + addr.str() + ".json");
		// ofstream out("out-datasetText/logStateTemp-" + getCurrentFileName() + "-" + addr.str() + ".json");
		ofstream out;
		out.open("out-datasetText/logState-" + getCurrentFileName() + "-" + addr.str() + ".json", std::ios_base::app);
		string wordToReplace(" ]}");
		string wordToReplaceWith(stateText + " ]}");

		if (!in)
		{
			cerr << "Could not open "
				 << "out-datasetText/logState-" + getCurrentFileName() + "-" + addr.str() + ".json"
				 << "\n";
			return;
		}

		if (!out)
		{
			cerr << "Could not open "
				 << "out-datasetText/logState-" + getCurrentFileName() + "-" + addr.str() + ".json"
				 << "\n";
			return;
		}

		string line;
		size_t len = wordToReplace.length();
		getline(in, line);

		size_t pos = line.find(wordToReplace);
		if (pos != string::npos)
		{
			// std::cerr << "Reading line: " << line << "\n";
			if (string::npos != line.find("[ ]}"))					// first element
				wordToReplaceWith.erase(wordToReplaceWith.begin()); //remove the ","

			line.replace(pos, len, wordToReplaceWith);

			// std::cerr << "Line replaced: " << line << "\n";
			// std::cerr << "\n";
		}

		out = ofstream("out-datasetText/logState-" + getCurrentFileName() + "-" + addr.str() + ".json");
		out << line;
	}
};
