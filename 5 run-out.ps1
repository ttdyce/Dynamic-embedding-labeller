$dir = "selected-data/"
$filter = $dir + "*.exe"

# init
New-Item -Name "out-datasetText/" -ItemType "directory" -Force

Get-ChildItem -filter $filter | ForEach-Object{
    $exe = $dir + $_.name
    "Working on " + $exe
    Get-Content input.txt | & $exe 
}