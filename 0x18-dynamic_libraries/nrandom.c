int rand();

int rand()
{
	int nums[] = {8, 8, 7, 9, 23, 74};
	static int i = 0;

	return (nums[i++]);
}
