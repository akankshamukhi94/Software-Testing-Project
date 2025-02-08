#!/bin/sh
echo "Starting test runner..."
test_runner="\\Mac/Home/C:\Program Files\Microsoft Visual 
Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\TestWindow\vstes
t.console.exe" 
tests_dll="SFT221 MS4\x64\Debug\Debug\UnitTestingfileMs4.dll" 
failure_string="Failed:"
testout=`"$test_runner" "$tests_dll"`
if [[ $testout == *"$failure_string"* ]]; then
 echo >&2 "Unit test are not passing! Push aborted!"
 exit 1
fi
echo >&2 "All tests run successfully."
exit 0
