#include <boost/algorithm/string.hpp>
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;
using namespace boost;

int main()
{
	cout<<"Starting download list file generation"<<endl;

	//what we want is to output a simple text file containing a list of urls to download
	int count = 0;

	ifstream input;

	input.open("carddata2.txt");

	if(!input.good())
		cout<<"Error reading file!"<<endl;

	string inputS = "";
	getline(input,inputS);
	string resultString = "";

	while(input.good())
	{
		vector <string> fields;

		if(count > 0)
		{
			split( fields, inputS, is_any_of( "\t" ) );

			string tempUrl = "https://dl.dropboxusercontent.com/u/73204375/pokemon/cards/"+fields[2]+".jpg";

			resultString = resultString + tempUrl + "\n";
			
			cout<<tempUrl<<endl;
		}

		count++;

		getline(input,inputS);
	}

	input.close();

	ofstream output;

	output.open("cardurls2.txt");
	output<<resultString;
	output.close();

	cout<<count<<endl;

	//this will take in the card data from both card data files and format it into urls that our chrome downloader will download
		//all urls should contain this

	//the result should be stored in a text file

	return 0;
}
