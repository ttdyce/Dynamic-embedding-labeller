$dir = "selected-data/"
$count = 0
Get-ChildItem $dir -Filter *.cpp | Foreach-Object {
    $in = $dir + $_.Name
    $out = $dir + $_.BaseName
    g++ $in -o $out
    "Done: " + ++$count + "(" + $_.Name + ")"
}