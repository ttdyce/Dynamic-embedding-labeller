$dir = "out-datasetText/"
# Get-ChildItem -filter $dir | ForEach-Object{
#     $_.BaseName
#     $t = $dir + $_.BaseName + ".txt"
#     (gc $t | Measure-Object -line ).Lines
# }

Get-ChildItem -filter $dir | Select-String "0 -> 0" | ForEach-Object {
    $_.BaseName
    $t = $dir + $_.BaseName + ".txt"
    (gc $t | Measure-Object -line ).Lines
}