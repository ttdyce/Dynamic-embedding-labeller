$dir = "selected-data/"
$count = 0
$max = 10 # set to -1 for all
Get-ChildItem $dir -Filter *.cpp | Sort-Object LastWriteTime -Descending | Foreach-Object {
    $in = $dir + $_.Name
    $out = $dir + $_.BaseName
    g++ $in -o $out
    "Done: " + ++$count + "(" + $_.Name + ")"
    $max--

    if ($max -eq 0){
        break
    }
}