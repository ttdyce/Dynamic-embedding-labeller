$dependencies = Get-Content "dependencies.txt"

Get-ChildItem "selected-data/" -Filter *.cpp | 
Foreach-Object {
    $content = ($_ | Get-Content)  -replace 'int ', 'Intercept<int> '
    $content = $content -replace 'void main', 'int main'
    $content = $content -replace 'Intercept<int> main', 'int main' 
    $content = $dependencies + $content

    Set-Content -Path $_.FullName -Value $content

    $content
}