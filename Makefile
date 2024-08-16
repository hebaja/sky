all: ./rush01
	@echo "All done!"
rush01:
	@echo "Compiling..."
	@gcc src/rush01.c src/table.c src/coord.c src/solve/*.c src/utils/ft_* -o rush01
clean:
	@echo "All clean!"
	@rm rush01
