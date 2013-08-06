/*
Write an efficient algorithm that searches for a value in an n x m table (two-dimensional array). This table is sorted along the rows and columns — that is,

Table[i][j] ≤ Table[i][j + 1], 
Table[i][j] ≤ Table[i + 1][j]
*/

//Start from the most left bottom ,using binary-search for left and top direction

#include <iostream>
using namespace std;

bool BinarySearch(int ary[3][4] , int fixed, bool row, int start, int end, int value ,int& index)
{
	int nStart= start, nEnd = end;
	int tmp;
	while( nStart <= nEnd)
	{
		int mid = (nStart + nEnd)/ 2;
		if( row )
		    tmp = ary[fixed][mid];
		else
		    tmp = ary[mid][fixed];
		if( tmp  == value)
		{
			index = mid;
			return true;
		}
		else if( tmp > value)
		{
			nEnd = mid - 1;
		}
		else
		{
			nStart = mid + 1;
		}
	}
	int startValue, endValue;
	if( row)
	{
		startValue = ary[fixed][start];
		endValue = ary[fixed][end];
	}
	else
	{
		startValue = ary[start][fixed];
		endValue = ary[end][fixed];
	}
	if(value < startValue )
	{
		index = start -1;
	}
	else if( value > endValue)
	{
		index = end + 1;
	}
	else
	{
		index = nStart;
	} 
	return false;
}

bool Search2D(int ary[3][4],int row,int column,int value)
{
	int nRow = row-1;
	int nColumn = 0;
	while( nRow >=0  && nColumn < column)
	{
		int current = ary[nRow ][nColumn];
		if(current  == value)
		{
			return true;
		}
		if(current > value)
		{
			int index;
			if(BinarySearch(ary,nColumn,false,0,nRow -1,value,index))
				return true;
			else
			{
				nRow = index -1;
			}
		}
		else
		{
			int index;
			if(BinarySearch(ary,nRow,true,nColumn,column,value,index))
				return true;
			else
			{
				nColumn = index ;
			}
		}
	}	
	return false;
}

int main(int argc, char * argv[])
{
	for(int i = 1; i < argc ;i++) 
	{
		int ary[3][4]= {{20, 30, 40 ,50},{60, 70, 80, 90},{100, 110, 120, 130}};
		bool ret = Search2D(ary,3,4, atoi(argv[1]));
		cout << "Found ? " << ret <<endl;
	}
}


