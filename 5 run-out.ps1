$dir = "selected-data/"
$filter = $dir + "*.exe"
$max = -1 # set to -1 for all

# init
if(Test-Path "out-datasetText/"){
    $cleanOutTextFolder = Read-Host 'out-datasetText/ exist! Would you like to delete all .json in the folder? (enter/n: No, y: Yes, delete)'
    if($cleanOutTextFolder -eq 'y'){
        Remove-Item "out-datasetText/*.json"

    }

}
New-Item -Name "out-datasetText/" -ItemType "directory" -Force

Get-ChildItem -filter $filter | Sort-Object LastWriteTime -Descending | ForEach-Object{
    $exe = $dir + $_.name
    "Working on " + $exe
    Get-Content input.txt | & $exe 
    $max--

    if ($max -eq 0){
        break
    }
}