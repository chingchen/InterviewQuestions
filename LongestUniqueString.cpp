#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;


struct FarNearPair
{
	FarNearPair(int f, int n)
	{
		far = f;
		near = n;
	}
	FarNearPair(){}
	int far;
	int near;
};

string LongestString(const string & src , int uniqueChars)
{
	if(src.length() == 0)
		return "";
	int far = 0;
	string currentLongest = "";
	int occupy = 0;
	map<char,FarNearPair> posMap;

	char preChar = src[0];
	posMap[src[0]] = FarNearPair(0,0);
	occupy ++;
	for( int i = 1; i < src.length() ; i++)
	{
		if(src[i] != preChar)
		{
			if(posMap.size() == uniqueChars &&  posMap.find(src[i]) == posMap.end())
			{
				if( i - far > currentLongest.length())
					currentLongest = src.substr(far, i-far);

				//Filter out the most left char
				int lowsestIndex = posMap.begin()->second.near;
				char toRemoveChar =   posMap.begin()->first;
				for( map<char,FarNearPair>::iterator start = posMap.begin(); start != posMap.end(); start++)	
				{
					if(start->second.near < lowsestIndex)	
					{
						lowsestIndex = start->second.near;
						toRemoveChar = start->first;;
					}
				}
				posMap.erase (toRemoveChar);

				//counter from the most left,after removing the original most left char 

				char mostLeftChar  = posMap.begin()->first;
				lowsestIndex = posMap.begin()->second.near;
				for( map<char,FarNearPair>::iterator start = posMap.begin(); start != posMap.end(); start++)	
				{
					if(start->second.near < lowsestIndex)	
					{
						lowsestIndex = start->second.near;
						mostLeftChar = start->first;;
					}
				}				
				far = 	posMap[mostLeftChar].far ;
			}
			preChar = src[i];
			posMap[src[i]] = FarNearPair( i,i);

		}
		else
		{
			posMap[src[i]].near = i;
			if( i - far > currentLongest.length())
					currentLongest = src.substr(far, i-far);
		}
	}
	if( currentLongest == "")
		return src;
	else
	{
		return currentLongest;
	}
}


int main(int argc, char * argv[])
{
	for(int i = 1; i < argc ;i+=2) 
	{
		string tmp = LongestString(argv[i],atoi(argv[i+1]));
		cout << tmp <<endl;
	}
}	
