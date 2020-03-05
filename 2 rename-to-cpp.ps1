Get-ChildItem "selected-data/" -Filter *.txt | 
Foreach-Object {
    Rename-Item -Path $_.FullName -NewName $_.FullName.replace(".txt", ".cpp")
    $_.FullName
}