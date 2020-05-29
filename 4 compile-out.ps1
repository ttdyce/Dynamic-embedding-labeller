# Stop-Transcript
# Start-Transcript -path log/output.log -append

$dir = "selected-data/"
$count = 0
$max = -1 # set to -1 for all
Get-ChildItem $dir -Filter *.cpp | Sort-Object LastWriteTime -Descending | Foreach-Object -Parallel{

    
    $in = $using:dir + $_.Name
    $out = $using:dir + $_.BaseName
    g++ $in -o $out
    
    "Done: " + ++$count + "(" + $_.Name + ")"
    $max--

    if ($max -eq 0){
        break
    }
}  -ThrottleLimit 20

# Stop-Transcript
