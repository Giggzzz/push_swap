

void	swap(int* stack)
{
	int	tmp;

	if (!stack[0] || !stack[1])
		return;
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}
