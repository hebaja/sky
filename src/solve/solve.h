#ifndef SOLVE_H
# define SOLVE_H

void	fetch_coord(char *str, int *coord);
void	print_coord(int *coord);
void	test_table(int rows, int cols, int **table);
void	tab_zeroes(int rows, int cols, int **table);
void	print_tab(int rows, int cols, int **table);
void	solve_complete_one_twos(int *coord, int **table);
void	solve_two_threes(int *coord, int **table);
void	solve_one_threes(int *coord, int **table);
void	solve_fix_one_two(int **table);
void	solve_missing_four(int **table);
int	is_coord_valid(int *coord);
int	solve_fours(int *coord, int **table);
int	solve_ones(int *coord, int **table);
int	solve_one_twos(int *coord, int **table);
int	solve_fours_from_three(int *coord, int **table);
int	solve_safe_middle_fours(int *coord, int **table);
int	solve_middle_fours_row(int *coord, int **table);
int	solve_middle_fours_col(int *coord, int **table);
int	solve_two_two_col(int *coord, int **table);
int	solve_two_two_row(int *coord, int **table);
int	solve_all_fours_found(int **table);
int	is_complete(int **table);

#endif
