/*
Filename:StarlightStudentRecordManagementSystem_SECTION3_GROUP1.cpp

Programmers name: 
GROUP 1
1)NURATHRISHA ELISA BINTI YUSRI (AM2307013881)
2)NUR ATHIRAH BINTI HILALLUDDIN (AM2307013911)
3)NUR FIKRIYAH HAFIEZAH BINTI MOHD FARID (AM2307013961)
4)NUR FARHANA BINTI FAUZI (AM2307013937)
5)MUHAMMAD NAQIB ASYRAAF BIN ARIFFIN (AM2307013890)

Date:20 November 2023

Program Description:This is Student Record Management System for a fictional school, Starlight High School .The school needs a program to and to manage student records ,
keep track of students personal information, including their names, student IDs,scores, and attendance. This program assist the school in maintaining and analyzing student's data.
*/

//header files
#include<iostream>
#include<iomanip>
#include <cctype>
#include <limits>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
void clearInputError();
//Nur Fikriyah Hafiezah's function prototype
int displayMenu(int numStudent);
//Nur Farhana's function prototype
void inputStudentData( int studentID[], string studentName[], double scores[], int attendance[], int numStudent, int currentStudent);
//Muhammad Naqib Asyraaf's function prototype
double calculateAverageScores(int numStudent, double scores[]);
void studentScoreByCategory(int numStudent, double scores[]);
//Nurathrisha Elisa's function prototype
void displayStudentRecords(int numStudent, int studentID[], string studentName[], double scores[], int attendance[], double average);
//Athirah Binti Hilalludin's function prototype
void displayTopLowRecord (int numStudent, int studentID[], string studentName[], double scores[] );

//Nur Fikriyah Hafiezah's Function 
int main()
{
	//max size of the array
	const int maxStudent = 100;
	
	//declare
	//	numStudent of number of existing student records
	int studentID[maxStudent], attendance[maxStudent], numStudent=0, currentStudent=0, tempStudent;
	string studentName[maxStudent];
	double scores[maxStudent], averagescores;
	int choice;
	char stop; 
  	//ask the user what they want to do with the program
	choice = displayMenu(numStudent);	
	
	//if the options are valid
	while(choice == 1 || choice == 2 ||choice == 3 || choice == 4){
		// option 1 : input students data
		if(choice == 1) {	
		//if no student record exist yet set number student to 50 because at least 50 student record is the requirement
			if (numStudent == 0){
				numStudent =50;
			} 
			else { //if student record already exist just ask user how many more student they want to add or append
				//ask user how many student they want to add
				cout<<"\nPlease enter the number of students: ";
				cin>>currentStudent;
				while(cin.fail()){
					clearInputError();
					cout<<"Invalid input. Please enter Integer only: ";
					cin>>currentStudent;
				}
				tempStudent = currentStudent;  // to temporarily hold add nuumStudent
				currentStudent = numStudent;  // currentStudent to store prev num of student before adding the new number of student
				numStudent = numStudent + tempStudent;	//add numStudent and currentStudent input to get the overall student record size 
			}		
			//Nur Farhana's part - input from user				
			for (int i = currentStudent; i < numStudent; i++) {
			    inputStudentData(studentID, studentName, scores, attendance, numStudent, i);
			}
		}
		//option 2: display student record and average scores
		else if (choice == 2){
			//Muhammad Naqib Asyraaf's part - calculate average score (function will return average)
			averagescores = calculateAverageScores( numStudent, scores);
			//Nurathrisha Elisa's part - display student record, average student score and searching student records
			displayStudentRecords(numStudent, studentID, studentName, scores, attendance, averagescores);		
		}				
		else if(choice == 3){
			//Athirah binti Hilalludin's part	
			displayTopLowRecord(numStudent, studentID, studentName, scores);
			cout<<"Please enter X to exit: ";
			cin>>stop;
			while(stop != 'X' && stop != 'x'){
			cout<<"Invalid Input. Please enter X only: ";
			cin>>stop;
			}	
		}
		else{
			studentScoreByCategory(numStudent, scores);
			cout<<"Please enter X to exit: ";
			cin>>stop;
			while(stop != 'X' && stop != 'x'){
				cout<<"Invalid Input. Please enter X only: ";
				cin>>stop;
			}
		}
		//ask the user what they want to do with the program next, whther to continue with other options or exit the program
		choice = displayMenu(numStudent);
	}
	cout<<"\n\nThankyou for using Starlight Management System! <3";	
	return 0;
}

//clear error cin
void clearInputError(){
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
	  
//Nur Fikriyah Hafiezah's part Menu Display    
//function to display menu, and handle invalid input during the menu, it will accept  numStudent bcs want to check if student record exists or not                                  
int displayMenu(int numStudent){
	int choice;
	system("CLS");
	cout<<"************************************************************\n";
	cout<<"            WELCOME TO STARLIGHT HIGH SCHOOL <3             \n";
	cout<<"************************************************************\n";
	cout<<" ---------------------------------------------------------\n";
	cout<<"|                        Menu Option                      |\n";
	cout<<" ---------------------------------------------------------\n";
	cout<<"|1- Input student records                                 |\n";
	cout<<" ---------------------------------------------------------\n";
	cout<<"|2- Student records & average scores                      |\n";
	cout<<" ---------------------------------------------------------\n";
    cout<<"|3- Display Top 5 & Lower 5 Student                       |\n";
	cout<<" ---------------------------------------------------------\n";
    cout<<"|4- Student's Score by Category                           |\n";
	cout<<" ---------------------------------------------------------\n";	
    cout<<"|5- Exit                                                  |\n";
    cout<<" ---------------------------------------------------------\n";
    cout<<"\nPlease choose your option : ";
	cin>>choice;
	
	//show invalid input if user enter other than 1/2/3/4, and ask the user to enter valid input	                                          
	while((choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5) || cin.fail()){
		if(cin.fail()){
			clearInputError();
		}
		cout<<"\nInvalid Input. Please enter 1/2/3/4/5 only: ";
		cin>>choice;
	}
	
	//if user enter option 2 & 3 but there is no student records available yet due to no input was done before, 
	//show an error message that there is no data and ask user to input student first
	while((choice == 2 || choice == 3 || choice == 4) && numStudent < 1){
		cout<<"\nNo data available. Please enter 1 to proceed on student details input: ";
		cin>>choice;		
	}
	
	//retun choice to know which option did the user choose
	return choice;
}

//Nur Farhana's function
// Function definition
void inputStudentData(int studentID[], string studentName[], double scores[], int attendance[], int numStudent, int currentStudent) {
    cout << "\nEnter details for student " << currentStudent + 1 << ":\n";

    cout << "Student ID (numeric only): ";
    cin >> studentID[currentStudent];
    //if user enters other than number, show error message and ask for correct input
	while(cin.fail()){
		clearInputError();
		cout << "Invalid input. Please enter a positive numeric value for User ID: ";
		cin >> studentID[currentStudent];
	}	             
	
	cout << "Student Name (alphabets only): ";
	//getline is used to accept name with spaces, instead of a single name
    cin.ignore();
    getline(cin, studentName[currentStudent]);
    //if user enters name containing digit, show error message and ask for a name containing alphabet and spaces only
	while(any_of(studentName[currentStudent].begin(), studentName[currentStudent].end(), ::isdigit)){
	  	cout << "Invalid input. Please enter alphabets and spaces only for Student Name: ";
	  	cin.ignore();
    	getline(cin, studentName[currentStudent]);
	}
	
    cout << "Scores (0 to 100): ";
    cin >> scores[currentStudent];
    //if user enters other than number or value is less than or more than 100, show error message and ask for correct input
	while(cin.fail() || scores[currentStudent] < 0 || scores[currentStudent] > 100){
		if(cin.fail()){
			clearInputError();
		}
		cout << "Invalid input. Please enter a value between 0 and 100 for Scores: ";
		cin >> scores[currentStudent];
	}


    cout << "Attendance (0 to 100): ";
    cin >> attendance[currentStudent];
    //if user enters other than number or value is less than or more than 100, show error message and ask for correct input
	while(cin.fail() || attendance[currentStudent] < 0 || attendance[currentStudent] > 100){
		if(cin.fail()){
			clearInputError();
		}
		cout << "Invalid input. Please enter a value between 0 and 100 for Attendance: ";
		cin >> attendance[currentStudent];
	}

    cout << "\n";
}

//Muhammad Naqib Asyraaf's function
//Function to calculate the average scores of students that already put in the array scores
double calculateAverageScores(int numStudent, double scores[]){
	double totalscores = 0, averagescores = 0;
	for( int i = 0; i < numStudent; i++){ //the input is not reached maximum of student
		totalscores= totalscores +scores[i]; // Calculate the total scores of all students
	}
	// Calculate the average score	
	averagescores = totalscores/numStudent;
	
	// Returning the average score
	return averagescores;
}

//Muhammad Naqib Asyraaf's function
//Function to display student list by scores category
void studentScoreByCategory(int numStudent, double scores[]){
	
	//declare count for all category
	int countScoreA = 0, countScoreB = 0, countScoreC = 0, countScoreFail = 0; 
	
	//loop through the array to count total number of students for each category
	for(int i = 0; i < numStudent; i ++ ){
		//if 80 above :add 1 to count category A
		if(scores[i] >= 80){
			countScoreA++;
		}			
		//if 79.9 - 60 : add 1 to count category B	
		else if(scores[i] >= 60 && scores[i] < 80){
			countScoreB++;
		}			
		//if 59.9 - 40 : add 1 to count category C
		else if(scores[i] >= 40 && scores[i] < 60 ){
			countScoreC++;
		}			
		// if less than 40 : add 1 to count category D	
		else{
			countScoreFail++;
		}
				
	}	
	//display summary of student score by category
	cout<<"\n***************     Summary of Student's Score by Category       ******************* \n";
	cout<<"\nA                ( 100% - 80% ) :              "<< countScoreA << " students\n";
	cout<<"B                (  79% - 60% ) :              "<< countScoreB << " students\n";
	cout<<"C                (  59% - 40% ) :              "<< countScoreC << " students\n";
	cout<<"D                (  40% -  0% ) :              "<< countScoreFail << " students\n";
	cout<<"\n************************************************************************************ \n";
	
}

//Nurathrisha Elisa's function 
//get maxstudent, studentID, studentName, scores, attendance and average from the int main to display inside the function
void displayStudentRecords(int numStudent, int studentID[], string studentName[], double scores[], int attendance[], double average){

	//clear screen before displaying student records
	system ("CLS");
	//design for the top display
	cout<<"\n\n";
	cout<<" ****************************************************************************************************************** \n";
	cout<<"|                                            Starlight High School                                                 |\n";                                                                                
	cout<<"|                                              Student Records                                                     |\n";
	cout<<" ****************************************************************************************************************** \n";
	cout<<"\n";
	cout<<" ------------------------------------------------------------------------------------------------------------------ \n";
	cout<<"|     Student ID     |    Score  |  Attendance  |               Student Name                                       |\n";
	cout<<" ------------------------------------------------------------------------------------------------------------------ \n";
	
	//loop through the student details array to display student's id, name, score and attendance for each student
	for( int j = 0; j < numStudent; j++){
		cout<<"|\t"<<studentID[j]<<"          |\t "<<fixed<<setprecision(2)<<scores[j]<<"\t |\t "<<attendance[j]<<" %\t|\t"<<studentName[j]<<" \n";	
	}
	cout<<" ------------------------------------------------------------------------------------------------------------------ \n";
	cout<<"\n\n";
	//display average student that was calculated by function calculateAverageScores()
	cout<<"------------------------------------------------------------------------------------------------------------------- \n";
	cout<<"Average scores for all students in the array scores is: "<< average;
	cout<<"\n-------------------------------------------------------------------------------------------------------------------";
	cout<<"\n\n";
	
	//searching part begins here
	int searchStu;//keyword for searching
	char searching;//status whether to do the searching
	
	//ask user if they want to search for student details
	cout<<"\nDo you want to search for a student? (Y/N): ";
	cin>>searching;
	
	//handle invalid input
	while((searching != 'Y' && searching != 'N' && searching != 'n' && searching != 'y') || cin.fail()){
		if(cin.fail()){
			clearInputError();
		}
		cout<<"\nInvalid Input. Please enter Y/N only: ";
		cin>>searching;
	}
	
	//if user want to search
	while(searching== 'Y'|| searching =='y'){
		// ask user for search id
		cout<<"\nPlease enter student ID (to view student's details): ";
		cin>>searchStu;	
		//if user input other than number
		while(cin.fail()){
			clearInputError();
			cout<<"\nInvalid Input. Please enter Integer only: ";
			cin>>searchStu;
		}
		//search will start from the first student record	
		int i = 0;
		//default not found
		bool found = false;
		//do the loop if still not found and current index is <= maxStudent (haven't gone through all student records)
		while (!found && i <= numStudent){
			//if current index student id is the same as search keyword, display student details
			if (searchStu == studentID[i]){
				cout<<"\n\nThis is the student details";
				cout<<"\n------------------------------------------------";
				cout<<"\nStudent ID  : "<<studentID[i];
				cout<<"\nName        : "<<studentName[i];
				cout<<"\nScore       : "<<scores[i];
				cout<<"\nAttendance  : "<<attendance[i]<<" %";
				cout<<"\n------------------------------------------------";
				//change found status to true to stop the searching process 
				found = true;	
			}
			//move to next student record
			i=i+1;
		}
		//if still not found meaning the student record with search id doesn't exist
		if (!found){
			cout<<"\nStudent with ID "<< searchStu<<" not found.\n";
		}
		
		//ask user if they want to do another search for student records
		cout<<"\nDo you want to search for another student (Y/N)? : ";
		cin>>searching;
		//handle invalid input
		while((searching != 'Y' && searching != 'N' && searching != 'n' && searching != 'y') || cin.fail()){
			if(cin.fail()){
				clearInputError();
			}
			cout<<"\nInvalid Input. Please enter Y/N only: ";
			cin>>searching;
		}
	} 
}

//Athirah binti Hilalludin's function definition in displaying best and low student based on their scores
void displayTopLowRecord(int numStudent, int studentID[], string studentName[], double scores[]) {
	
	// Create vectors to store the original indices of students before sorting based on scores.
	//for calculating top student
    vector<int> topIndices(numStudent); 
    iota(topIndices.begin(), topIndices.end(), 0); 
    sort(topIndices.begin(), topIndices.end(), [&](int a, int b) { return scores[a] > scores[b]; }); 

	//for calculating lower student
    vector<int> lowIndices(numStudent); 
    iota(lowIndices.begin(), lowIndices.end(), 0); 
    sort(lowIndices.begin(), lowIndices.end(), [&](int a, int b) { return scores[a] < scores[b]; });

	//will display an output of top students
    cout << "\n*******************************************" << endl;
    cout << "      Top 5 Students based on Scores      " << endl;
    cout << "*******************************************" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "|" << left << setw(6) << "Rank" << setw(10) << "ID" << setw(15) << "Name" << setw(10) << "Score" << "|" << endl;
    cout << "-------------------------------------------" << endl;

    for (int i = 0; i < min(numStudent, 5); ++i) {
        int topIndex = topIndices[i];
        cout << "|" << left << setw(6) << i + 1 << setw(10) << studentID[topIndex] << setw(15) << studentName[topIndex].substr(0, 15) << setw(10) << fixed << setprecision(2) << scores[topIndex] << "|" << endl;
    }
    
    cout << "-------------------------------------------" << endl;
	
	//will display an output of lower student
    cout << "\n*******************************************" << endl;
    cout << "     Lower 5 Students based on Scores     " << endl;
    cout << "*******************************************" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "|" << left << setw(6) << "Rank" << setw(10) << "ID" << setw(15) << "Name" << setw(10) << "Score" << "|" << endl;
    cout << "-------------------------------------------" << endl;

    for (int i = 0; i < min(numStudent, 5); ++i) {
        int lowIndex = lowIndices[i];
        cout << "|" << left << setw(6) << i + 1 << setw(10) << studentID[lowIndex] << setw(15) << studentName[lowIndex].substr(0, 15) << setw(10) << fixed << setprecision(2) << scores[lowIndex] << "|" << endl;
    }

    cout << "-------------------------------------------" << endl;
}
