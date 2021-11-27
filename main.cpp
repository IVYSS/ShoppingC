//Heaader
#include <stdio.h> 
#include <stdlib.h> // libary
#include <windows.h> // use fucntions system.
#include <iostream> // input output.
#include <cstdio>
#include <fstream> // use read and write file text.txt.
#include <string> // use string functino.
#include <cstring> // find len of text.
using namespace std;

void writeFile(int idArr[5], string nameArr[5], int priceArr[5], int dcArr[5]){
	ofstream MyFile("Data.txt");
	for(int i;i < 5;i++){
		// writeFile loop data
		MyFile  << idArr[i] << " " << nameArr[i] << " " << priceArr[i] << " " << dcArr[i] << endl;
	}
	MyFile.close();
}

void sumOrder(string nameArr[5], int piecesArr[5], int sumArr[5]){
	/* sumamry order on bill*/
	cout << "\n__________________________This is your Order________________________\n\n";
	for(int n=0; n < 5; n++){
		if(nameArr[n].length() <= 6){
		//	check len space bar \t
			cout <<"\t" <<nameArr[n] << "\t\t" << "\tpieces : " << piecesArr[n] << "\t" << sumArr[n] << endl ;
		}
		else{
			cout <<"\t" <<nameArr[n] << "\t" << "\tpieces : " << piecesArr[n] << "\t" << sumArr[n] << endl;
		}
	}
	// Order Total
	int sumPrice = 0; // last price
	for(int s=0; s < 5; s++){
		sumPrice += sumArr[s]; //sumPrice
	}
	cout << "\tOrder Total :" << "\t\t\t\t" << sumPrice << "  Baths.\n";
}

int cashCheck(int sumPrice, string nameArr[5], int piecesArr[5], int sumArr[5]){
	/* check cash and check Change from cash*/
	int cash; // input cash
	while (true){
		cout << "Please put money :  ";
		cin >> cash;
		cout << endl;
		cout << "------------------------\n";
		int calLess = abs(cash - sumPrice);
		if(cash < 0){
			cout << "\nPlease try again...... \n\n";
		}
		else if(cash < sumPrice){
			cout << "Payment is still "<< calLess << " Bahts short.\n\n";
			cout << "\nPlease try again...... \n\n";
			}
		else if(cash >= sumPrice){
			sumOrder(nameArr, piecesArr, sumArr);
			cout << "\tCash: \t\t\t\t\t" << cash << "  Baths.\n";
			cout << "\tChange: \t\t\t\t" << calLess << " Bahts.\n";
			cout << "\n\t\t-----------THANK YOU-----------\n" << "\t\t   ----- Cheack Closed ----";
			break;
		}
	}
}

void customer(int idArr[5], string nameArr[5], int priceArr[5], int dcArr[5]){
	/* show menu and price , discount , select number menu , aand show bill*/
	cout << "\n____________________________________MANU Fast Food___________________________\n\n";
	int numberOrder;
	int bathArr[5]; // bath - discount
	int piecesArr[5]; // how much
	int sumArr[5]; // keep last price
	for (int i = 0; i < 5; ++i) {
		//		show manu
		bathArr[i] = priceArr[i] - (priceArr[i] * dcArr[i] / 100);
		cout << "["<< idArr[i] <<"]\t"
		<<" : ";
		if (nameArr[i].length() < 5){
			cout  <<nameArr[i]<< "\t\t";
		}
		else{
			cout<<nameArr[i] << "\t" ;
		}

		cout << "\t\tprice :" << priceArr[i]
		<< "\tDISCOUNT : " << dcArr[i] << "% "
		<< "\tLast price :  " << bathArr[i] << "  Bath."<< endl;
    }
    cout << "\n____________________________________________________________________________\n\n";
//   input pieces of Oders
    cout << "\n|-------------------How many pieces do you want ?-------------------|\n"
    << "\tif you not want this order : pull number 0\n\n";
	for(int num = 0; num < 5; num++){
		if(nameArr[num].length() <= 6){
		//	check len space bar \t
		cout <<"\t" << nameArr[num] << "\t\t" << "\tpieces : ";
		}
		else{
			cout <<"\t" << nameArr[num] << "\t" << "\tpieces : ";
		}
		cin >> piecesArr[num]; // input pieces
		if (piecesArr[num] < 0){
			cout << "\n-----------Plase select pieces between 0-10 -----------------\n\n";
			num = num - 1;
		}
		else{
			sumArr[num] = bathArr[num] * piecesArr[num];
		}
	}
	// summary order
	sumOrder(nameArr,piecesArr, sumArr);
	
	// loop sum price
	int sumPrice = 0;
	for(int s=0; s < 5; s++){
		sumPrice += sumArr[s];
	}
	cout << "\n____________________________________________________________________\n";
	int confirm;
	cout << "\nConfirm your order (1 = yes/2 = no):  ";
	cin >> confirm;
	cout << endl;
	if(confirm == 1){
		cashCheck(sumPrice, nameArr, piecesArr, sumArr);
	}else{
		cout << "\nPlease try again......\n";
	}
}

int employee(int idArr[5], string nameArr[5], int priceArr[5], int dcArr[5]){
	/* this function form edit discount*/
	cout << "\n\n----------------------------- Edit Menu -------------------------\n";
	// show menu
	for (int i = 0; i < 5; ++i) {
		//		show manu
        cout << "["<< idArr[i] <<"]\t"
		<<" : ";
		if (nameArr[i].length() < 5){
			cout  <<nameArr[i]<< "\t\t";
		}
		else{
			cout<<nameArr[i] << "\t" ;
		}
		cout << "\t\tprice :" << priceArr[i]
		<< "\tDISCOUNT : " << dcArr[i] << "% " << endl;
    }
    
    cout << "Select menu to edit (number 1-5): ";
    int discountArr[3] = {10, 20, 30}; // %
    int menu;
    cin >> menu;
    menu = menu - 1;
    while(true){
	    if(menu >= 0 && menu < 5){
	    	// show menu again
	    	cout << "----------------- Menu " << menu + 1 << "----------------\n";
		    cout << "["<< idArr[menu] <<"]\t"
			<<" : " << nameArr[menu]
			<< "\t\tprice :" << priceArr[menu]
			<< "\tDISCOUNT : " << dcArr[menu] << "% \n"
			<< "\t    [1]\t\t\t  [2]\t\t[3]\n" << "Select your section (number 1-3):  ";
			int section;
			cin >> section;
			//check select to edit
			if(section == 1){
				string name;
				cout << "Edit menu name (none-space): ";
				cin >> name;
				nameArr[menu] = name;
				cout << "\n-----------Edit menu name is success-----------\n";
				
			}else if(section == 2){
				int price;
				cout << "Edit menu price : ";
				cin >> price;
				priceArr[menu] = price;
				cout << "\n-----------Edit menu price is success-----------\n";
				
			}else if(section == 3){
				// check choice to discount
				cout << "---------------Select you promotion --------------------\n"
				<< "[1] :  " << discountArr[0] << "%  [2] :  " <<  discountArr[1]  << "%  [3] :  " <<  discountArr[2]  << "%"
				<< "\nEdit menu discount (number 1-3): ";
				int select_discount;
				cin >> select_discount;
				if(select_discount < 4){
					dcArr[menu] = discountArr[select_discount-1];
					cout << "\n-----------Edit menu discount is success-----------\n";
				}else{
					cout << "\nPlease try again......\n";
					Sleep(1500);
					employee(idArr, nameArr, priceArr, dcArr);
				}
			}
			else{
				cout << "\nPlease try again......\n\n";
				employee(idArr, nameArr, priceArr, dcArr);
			}
		}
		else
		{
			cout << "\nPlease try again......\n\n";
			employee(idArr, nameArr, priceArr, dcArr);
		}
		
		cout << "Would you like to do another transection (1=Yes, 2=No, 3=Exit) :  ";
		int con;
		cin >> con; //check Selecttion (1 yes 2 No 3 Exit)
		if (con == 1){
			// calling function weiteFile
			continue;
		}
		else if(con == 2){
			writeFile(idArr, nameArr, priceArr, dcArr);
			cout << "\n-----------Edit menu success-----------\n";
			employee(idArr, nameArr, priceArr, dcArr);
			break;
		}else if (con == 3){
			writeFile(idArr, nameArr, priceArr, dcArr);
			break;
		}else{
			cout << "\nPlease try again......\n";
			Sleep(1500); 
			system("cls");
		}
	}	
}


int runner(){
	system("color 5e"); //color 
//	read File data.txt
	int idArr[5]; 
	string nameArr[5];
	int priceArr[5];
	int dcArr[5];
	ifstream inFile;
	inFile.open("Data.txt");
	if(inFile.is_open()){
		int id;
		string name;
		int price;
		int discount;
		int count = 0;
		while(inFile >> id >> name >> price >> discount){
			string keepData[5] = {};
			idArr[count] = id;
			nameArr[count] = name;
			priceArr[count] = price;
			dcArr[count] = discount;
			count++;
		}
		inFile.close();
	}
	else{
		cout << "Unable to Find text" << endl;
		Sleep(1500);
		system("cls");
	}

//	main runner
	int role;
	while(true){
		cout 
		<< "|-------------------------------------------------------|\n" 
		<< "|-------------------------------------------------------|\n" 
		<< "|             Fast Food Ordering System                 |\n" 
		<< "|-------------------------------------------------------|\n"
		<< "|-------------------------------------------------------|\n" 
		<< "\t[1] :  Customer\n" 
		<< "\t[2] :  Employee\n"
		<< " Select number of your role (1,2): ";
		cin >> role;
		if(role == 1){
			customer(idArr, nameArr, priceArr, dcArr);
			break;
		}else if (role == 2){
			employee(idArr, nameArr, priceArr, dcArr);
			break;
		}else{
			cout << "\n Select your role "<<"please try again." << endl;
			Sleep(1200);
			system("cls"); //close progrem	
		}
	}
}

//main for runing program
int main()
{
	runner();
  	return 0;
}
