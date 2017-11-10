// Reza Naeemi

/*
1) BubbleSort
2) InsertSort
3) MergeSort
4) Non-Recursive, One Extra items MergeSort (We’ll call this improved version,
IterativeMergeSort from here on out in this homework)
5) QuickSort
*/


#ifndef SORTIMPLS_H
#define SORTIMPLS_H

#include <iostream>
#include <vector>

using namespace std;

// Bubble Sort
void BubbleSort(vector<int> &items, int first, int last)
{
	for (int item = last; item >= first; item--)
	{
		for (int index = first + 1; index <= item; index++)
		{
			if (items[index - 1] > items[index])
			{
				int temp = items[index - 1];
				items[index - 1] = items[index];
				items[index] = temp;
			}
		}
	}
}


// Insert Sort
void InsertSort(vector<int> &items, int first, int last)
{
	int size = 1 + (last - first); // Calculating size using first and last to handle any range
	for (int index = first + 1; index < size; index++)
	{
		int temp = items[index];
		int loc = index;

		while ((loc > first) && (items[loc - 1] > temp))
		{
			items[loc] = items[loc - 1];

			loc--;
		}

		items[loc] = temp;
	}
}

// Merge Sort
void MergeSortAssistant(vector<int> &items, int first, int mid, int last)
{
	vector<int> tempArray(items);

	int first1 = first;
	int last1 = mid;
	int first2 = mid + 1;
	int last2 = last;

	int index = first1;

	while ((first1 <= last1) && (first2 <= last2))
	{
		if (items[first1] <= items[first2])
		{
			tempArray[index] = items[first1];
			first1++;
		}
		else
		{
			tempArray[index] = items[first2];
			first2++;
		}

		index++;
	}

	while (first1 <= last1)
	{
		tempArray[index] = items[first1];

		first1++;
		index++;
	}

	while (first2 <= last2)
	{
		tempArray[index] = items[first2];

		first2++;
		index++;
	}

	for (index = first; index <= last; index++)
	{
		items[index] = tempArray[index];
	}

}

void MergeSort(vector<int> &items, int first, int last)
{
	if (first < last)	// Controls Range input ???
	{
		// Same as (first + last) / 2, but avoids overflow for larger first and last nums
		int mid = first + (last - first) / 2;

		MergeSort(items, first, mid);
		MergeSort(items, mid + 1, last);
		MergeSortAssistant(items, first, mid, last);
	}
}



// Iterative Merge Sort
void IterativeMergeSort(vector<int> &items, int first, int last)
{
	int size = last - first + 1;
	vector<int> tempArray(size);

	for (int i = 1; i < size; i *= 2)
	{
		for (int j = first; j < size - i; j += 2 * i)
		{
			int first = j;
			int mid = j + i - 1;
			int last;
			if (j + 2 * i - 1 < size - 1)
			{
				last = j + 2 * i - 1;
			}
			else
			{
				last = size - 1;
			}

			for (int i = first; i <= last; i++)
			{
				tempArray[i] = items[i];
			}

			int first2 = first;
			int current = first;
			int high2 = mid + 1;

			while (current <= last)
			{
				if (high2 <= last && (tempArray[first2] > tempArray[high2] || first2 > mid))
				{
					items[current++] = tempArray[high2++];
				}
				else
				{
					items[current++] = tempArray[first2++];
				}
			}
		}
	}


}


// Quick Sort
int Partition(vector<int> &items, int beg, int end)
{
	int p = beg;
	int pivot = items[beg];

	for (int location = beg + 1; location <= end; location++)
	{
		if (pivot > items[location])
		{
			items[p] = items[location];
			items[location] = items[p + 1];
			items[p + 1] = pivot;

			p++;
		}
	}

	return p;
}

void QuickSort(vector<int> &items, int beg, int end)
{
	if (beg < end)
	{
		int p = Partition(items, beg, end);

		QuickSort(items, beg, p - 1);
		QuickSort(items, p + 1, end);
	}
}


#endif // SORTIMPLS_H
