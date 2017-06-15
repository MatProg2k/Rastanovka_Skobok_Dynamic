#include "MatricaMul.h"

MatricaMul::MatricaMul(int count, std::vector<int> size)
{
	this->count = count;
	this->size = size;

	this->resultMatrica = new int*[this->count];

	for (int i = 0; i < this->count; i++)
	{
		this->resultMatrica[i] = new int[this->count];
		for (int j = 0; j < this->count; j++)
		{
			this->resultMatrica[i][j] = 0;
		}
	}
}

int MatricaMul::GenerationDinamic()
{
	int minMult = INT32_MAX;

	for (int i = 0; i < this->count * this->count; i++)
	{
		this->resultForDinamic.push_back(-1);
	}

	for (int i = 1; i < this->count + 1; i++)
	{
		this->resultForDinamic[this->GetIndex(i, i)] = 0;
	}

	for (int l = 0; l < this->count - 1; l++)
	{
		for (int i = 1; i < this->count - l; i++)
		{
			int j = i + l + 1;
			this->resultForDinamic[this->GetIndex(i, j)] = INT32_MAX;
			for (int k = i; k < j; k++)
			{
				minMult = this->resultForDinamic[this->GetIndex(i, k)] +
					this->resultForDinamic[this->GetIndex(k + 1, j)] +
					this->size[i - 1] * this->size[k] * this->size[j];

				if (minMult < this->resultForDinamic[this->GetIndex(i, j)])
				{
					this->resultForDinamic[this->GetIndex(i, j)] = minMult;
					this->resultMatrica[i - 1][j - 1] = k;
				}
			}
		}
	}

	return this->resultForDinamic[this->GetIndex(1, this->count)];
}

void MatricaMul::ShowResultMatrica()
{
	std::cout << "Результирующая матрица:" << std::endl;
	for (int i = 0; i < this->count; i++)
	{
		for (int j = 0; j < this->count; j++)
		{
			std::cout << this->resultMatrica[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int MatricaMul::GetIndex(int i, int j)
{
	return (i - 1) * this->count + (j - 1);
}


