for file in $(find test -iname "*.sol"); do
	ALLOUTPUT=$(build/solc/solc --combined-json ast,compact-format --pretty-json $file --stop-after parsing 2>&1)
	if test "$?" != "0"; then
		# solc returned failure. Compilation errors are okay, everything
		# else is a failed test (segfault)
		if ! echo $ALLOUTPUT | grep "Error:" -q; then
			echo "Test failed on $file!";
			exit 1;
		fi
	fi
done
