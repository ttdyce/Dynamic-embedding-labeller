$dirRoot = '../'
$dir = $dirRoot + 'c/1/'
$dirOut = 'selected-data/'
# $dirDict = 'dict/'
# $dictName = 'gatherer.txt'

# $content = Get-Content "$($dirDict)$($dictName)"
# $content.Split('`r')

$i = 0
Get-ChildItem -Recurse $dir | Select-String "int sum" | ForEach-Object {
    if ($i -ge 500) {
        break
    }
    
    $path = $_.Path
    Copy-Item $path -Destination $dirOut

    $i ++
    $i
}