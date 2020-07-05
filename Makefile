cpp_formatter=clang-format
cpp_formatter_options=-style=Google -i --verbose
file_pattern='.*\.\(cpp\|hpp\|cc\|cxx\|java\|js\)'
exec_pattern='.*\.\(out\|class\)'

# Formats everything
format:
	@printf "Formatting all files...\n"
	@find . -regex $(file_pattern) -exec $(cpp_formatter) $(cpp_formatter_options) {} \;
	@printf "done\n"

# Removes .out and .class files
clean:
	@printf "Cleaning executables...\n"
	@find . -regex $(exec_pattern) -type f -delete
	@printf "done\n"
