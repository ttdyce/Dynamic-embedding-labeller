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

		// logVariableTraceText(-1, temp);
		// std::stringstream addr;
		// addr << &t_;
		// ofstream logFile("out-datasetText/log-" + getCurrentFileName() + "-" + to_string(label) + "-" + addr.str() + ".txt", std::ios_base::app);
		// logFile << -1 << " -> " << t << '\n';
	}
	Intercept(const T &t, int l) : t_(t)
	{
		label = l;

		std::stringstream addr;
		addr << &t_;
		ofstream logFile("out-datasetText/log-" + getCurrentFileName() + "-" + to_string(label) + "-" + addr.str() + ".txt", std::ios_base::app);
		logFile << -1 << " -> " << t << '\n';
	}

	T operator=(const T &t)
	{
		logVariableTraceText(t_, t);
		//std::cerr << "change " << t_ << " to " << t << '\n';
		t_ = t;
		return *this;
	}
	T &operator++()
	{
		T temp = t_ + 1;
		logVariableTraceText(t_, temp);
		// std::cerr << "(++x)change " << t_ << " to " << temp << '\n';

		t_ = temp;
		return t_;
	}
	T &operator++(int)
	{
		prev = t_;
		T temp = t_ + 1;

		logVariableTraceText(t_, temp);
		// std::cerr << "(x++)change " << t_ << " to " << temp << '\n';

		t_ = temp;
		return prev;
	}
	T operator+=(const T &t)
	{
		T oldT = t_;
		t_ = t_ + t;

		logVariableTraceText(oldT, t_);
		// std::cerr << "(+=)change " << oldT << " to " << t_ << '\n';
		return *this;
	}
	T &operator--()
	{
		T temp = t_ - 1;
		logVariableTraceText(t_, temp);
		// std::cerr << "(++x)change " << t_ << " to " << temp << '\n';

		t_ = temp;
		return t_;
	}
	T &operator--(int)
	{
		prev = t_;
		T temp = t_ - 1;

		logVariableTraceText(t_, temp);
		// std::cerr << "(x++)change " << t_ << " to " << temp << '\n';

		t_ = temp;
		return prev;
	}

	operator T &() { return t_; }
	operator const T &() const { return t_; }
	T t_, prev;
	int label;

	string getCurrentFileName()
	{
		char buffer[MAX_PATH];
		GetModuleFileName(NULL, buffer, MAX_PATH);
		string::size_type pos = string(buffer).find_last_of("\\/");
		// std::cerr << "Got file name: " << string(buffer).substr(pos+1, string(buffer).find_last_of("."));
		return string(buffer).substr(pos + 1, string(buffer).find_last_of("."));
	}

	void logVariableTraceText(Intercept<int> a, Intercept<int> b)
	{
		if (label == 0)
			return;
		std::stringstream addr;
		addr << &t_;
		ofstream logFile("out-datasetText/log-" + getCurrentFileName() + "-" + to_string(label) + "-" + addr.str() + ".txt", std::ios_base::app);
		logFile << a << " -> " << b << '\n';

		// std::cerr << "change " << a << " to " << b << '\n';
	}
};