#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <set>
#include <algorithm>

using namespace std; // Removes std in std::cout, std::cin, std::endl; etc..

// Forms a structure to represent a question, answer choices, and answers. Only applied in MCQ.
struct Question {
    string questionText; // Text of the question
    vector<string> answerChoices; // Answer Choices 
    int correctAnswer; // Index of the correct answers in answerChoices
};


// Category 1: Discrete Structures/Mathematics (Function to handle questions and answers related to Discrete Structures Literature)

void questionsDiscrete(){

    // A vector of Questions, Choices, and Index Answers of Discrete Structures Questions
    vector<Question> DiscreteQuestions = {
        {"What is the logical operator when the proposition's truth value changed to its inverse truth value?", 
         {"AND", "OR", "NOT", "XOR"}, 2},
        {"What type of conditional statement when the hypothesis (p) and conclusion (q) are switched?",
         {"Converse", "Inverse", "Contrapositive", "Tautology"}, 0},
        {"What type of conditional statement when the hypothesis (p) and conclusion (q) are switched and negated?", 
         {"Converse", "Inverse", "Contrapositive", "Tautology"}, 2},
        {"Which of the following is a proposition?", 
         {"2 + 2 = 4", "What time is it?", "Close the door", "All of the above"}, 0},
        {"If proposition p is true and q is false, what is the truth value when p ^ q?",
         {"True", "False"}, 1},
        {"What do you call a proposition that is always true?",
         {"Tautology", "Contradiction", "Contingency", "Proposition"}, 0},
        {"What is a proposition that is neither a tautology nor contradiction?",
         {"Tautology", "Contradiction", "Contingency", "Proposition"}, 2},
        {"If proposition (p) is TRUE and proposition q is FALSE, what is the truth value of p XOR q?",
         {"True", "False"}, 0},
        {"What is the propositional logic operator when either of the proposition's truth values are true but not both?",
         {"AND", "OR", "NOT", "XOR"}, 3},
        {"In cryptography, which letter is the most commonly used in the English language?",
         {"E", "A", "T", "O"}, 0}
    }; 
                                    
    int numberOfQuestions = DiscreteQuestions.size(); // Total number of questions
    set<int> selectedIndices; // Sets to store unique random indices

    srand(static_cast<unsigned int>(time(0))); // Random Number Generator

    // Selects up to 10 unique questions
    while (selectedIndices.size() < min(10, numberOfQuestions)){

        int randomIndex = rand() %  numberOfQuestions; // Generates Random Index
        selectedIndices.insert(randomIndex); // Insert the index in the set

    }

    int scoreDiscrete = 0; // Initializes the score for the DS

    // Loop for displaying questions (i) and choices (j)
    for (int i : selectedIndices){

        cout << "\n" << i + 1 << ". " << DiscreteQuestions[i].questionText << "\n";

        for (int j = 0; j < DiscreteQuestions[i].answerChoices.size(); j++){

            cout << char ('A' + j) << ". " << DiscreteQuestions[i].answerChoices[j] << "\n";
        }

        char userAnswer; // Variable to store user's answer
        bool validInputChoice = false; // Flag for valid input
        int answerIndex = -1; // Initializes the user's answer
        
        // Input loop for user's answer
        while (!validInputChoice){
            cout << "Enter the letter for your answer: ";
            cin >> userAnswer;
            
            userAnswer = toupper(userAnswer); // Converts to uppercase when the user inputs a lowercase character
    
            answerIndex = userAnswer - 'A'; // Convert letter to index through ASCII
            
            // Checks if the input is valid
            if (answerIndex >= 0 && answerIndex < DiscreteQuestions[i].answerChoices.size()) {
                validInputChoice = true; // Valid input
                
            } else { 
                cout << "\nInvalid answer. Please enter a number between A and " << char ('A' + DiscreteQuestions[i].answerChoices.size() - 1) << ".\n";
                continue; // Prompt again
    
            }
        }
        
        // Checks if the answer is correct
        if (answerIndex == DiscreteQuestions[i].correctAnswer){
            cout << "Correct!\n";
            scoreDiscrete++; // Increment by 1 point

        } else {
            cout << "Wrong! The correct answer is " << DiscreteQuestions[i].answerChoices[DiscreteQuestions[i].correctAnswer] << "\n";
        
        }



    }

    // Display the final score
    cout << "\nYour final score is: " << scoreDiscrete << " out of " << selectedIndices.size() << ".\n";

}


// Category 2: English Literature (Function to handle questions and answers related to English Literature)

void questionsEnglishLiterature(){

    // Vector of questions to English Literature
    vector<string> questions = {
        "1. Who wrote 'Pride and Prejudice'?",
        "2. What is the first name of Mr. Darcy in 'Pride and Prejudice'?",
        "3. Who is the author of '1984'?",
        "4. What is the name of the wizarding school in 'Harry Potter'?",
        "5. Who wrote 'To Kill a Mockingbird'?",
        "6. What is the name of the main character in 'Moby Dick'?",
        "7. Who wrote 'The Great Gatsby'?",
        "8. What is the name of the island in 'Lord of the Flies'?",
        "9. Who wrote 'Jane Eyre'?",
        "10. What is the name of Sherlock Holmes' assistant?"
    };

    // Vector of answers to their respective questions or indexes
    vector<string> answers = {
        "Jane Austen",
        "Fitzwilliam",
        "George Orwell",
        "Hogwarts",
        "Harper Lee",
        "Ishmael",
        "F. Scott Fitzgerald",
        "Uninhabited",
        "Charlotte Bronte",
        "Dr. Watson"
    };

   vector<string> userAnswers; // Vector to store user answers
   userAnswers.resize(questions.size()); // Resize to match number of questions
   int scoreEnglish = 0; // Initializes score for English Literature category

    cout << "Welcome to the English Literature Quiz!" << endl;
    cout << "\nPlease answer the following questions:" << endl;

    // For loop of the questions
    for (int i = 0; i < questions.size(); i++) {
        cout << questions[i] << endl; // Displays questions
        getline(cin >> ws, userAnswers[i]); // Get line of the user's answers

        // Converting both user answer and correct answer to lowercase and remove whitespaces
        string userAnswerLower = userAnswers[i];
        string correctAnswerLower = answers[i];
        
        transform(userAnswerLower.begin(), userAnswerLower.end(), userAnswerLower.begin(), ::tolower);
        transform(correctAnswerLower.begin(), correctAnswerLower.end(), correctAnswerLower.begin(), ::tolower);

        userAnswerLower.erase(remove_if(userAnswerLower.begin(), userAnswerLower.end(), ::isspace), userAnswerLower.end());
        correctAnswerLower.erase(remove_if(correctAnswerLower.begin(), correctAnswerLower.end(), ::isspace), correctAnswerLower.end());

        // Checks if the user's matches the correct answer
        if (userAnswerLower == correctAnswerLower) {
            scoreEnglish++; // Increments by 1 point
        }
    }

    // Displays the final overall score
    cout << "You scored " << scoreEnglish << " out of 10!" << endl;

}


// Category 3: Mathematics (Function to handle questions and answers related to Mathematics)

void questionsMath(){

    // Set of questions, choices, and index answers, which follows the format of the structure function
    vector<Question> MathQuestions = {
        {"What is 2 + 2?", {"3", "4", "5", "6"}, 1},
        {"What is the square root of 16?", {"2", "3", "4", "8"}, 2},
        {"What is 5 * 7?", {"30", "35", "40", "45"}, 1},
        {"What is 100 / 10?", {"10", "20", "5", "1"}, 0},
        {"What is 2^3?", {"6", "8", "9", "12"}, 1},
        {"What is 7 - 3?", {"3", "4", "5", "6"}, 1},
        {"What is 15 % 4?", {"1", "2", "3", "4"}, 2},
        {"What is the value of π (pi)?", {"3.14", "2.71", "1.61", "4.13"}, 0},
        {"What is 25 squared?", {"50", "125", "625", "1000"}, 2},
        {"What is 1/2 as a decimal?", {"0.25", "0.5", "0.75", "1.0"}, 1},
        {"What is the next number in the sequence: 2, 4, 6, 8?", {"10", "12", "14", "16"}, 0},
        {"What is the largest prime number less than 10?", {"5", "7", "9", "3"}, 1},
        {"What is the sum of angles in a triangle?", {"90", "180", "270", "360"}, 1},
        {"What is the area of a rectangle with length 5 and width 3?", {"8", "15", "16", "20"}, 1},
        {"What is the value of x in 2x = 10?", {"2", "5", "10", "20"}, 1}
};
                                    
    int numberOfQuestions = MathQuestions.size(); // Total number of questions
    set<int> selectedIndices; // Set to store unique random indices for selected questions

    srand(static_cast<unsigned int>(time(0))); // Random number generator

    // Randomly selecting to 10 different questions from the vector
    while (selectedIndices.size() < min(10, numberOfQuestions)){

        int randomIndex = rand() %  numberOfQuestions; // Random index generator
        selectedIndices.insert(randomIndex); // Insert the index into the set

    }

    int scoreMath = 0; // Initializes the score
    int questionMathCounter = 1; // Counter for question numbering

    // A for loop to generate questions (i) and display choices (j)
    for (int i : selectedIndices){

        cout << "\n" << questionMathCounter++ << ". " << MathQuestions[i].questionText << "\n";

        for (int j = 0; j < MathQuestions[i].answerChoices.size(); j++){

            cout << char ('A' + j) << ". " << MathQuestions[i].answerChoices[j] << "\n";
        }

        char userAnswer; // Variable to store user's input (answer)
        bool validInputChoice = false; // Valid input
        int answerIndex = -1; // Index for the user's answer
        
        // Input loop for user's answer
        while (!validInputChoice){
            cout << "Enter the letter for your answer: ";
            cin >> userAnswer; 
            
            userAnswer = toupper(userAnswer); // Converts lowercase to uppercase
            answerIndex = userAnswer - 'A'; // Convert letter into index through ASCII
            
            // Checking the input is valid
            if (answerIndex >= 0 && answerIndex < MathQuestions[i].answerChoices.size()) {
                validInputChoice = true; // Valid input
                
            } else { 
                cout << "\nInvalid answer. Please enter a number between A and " << char ('A' + MathQuestions[i].answerChoices.size() - 1) << ".\n";
                continue; // Prompt again
    
            }
        }

        // Checks if the answer is correct
        if (answerIndex == MathQuestions[i].correctAnswer){
            cout << "Correct!\n";
            scoreMath++; // Increment by 1

        } else {
            cout << "Wrong! The correct answer is " << MathQuestions[i].answerChoices[MathQuestions[i].correctAnswer] << "\n";
        
        }



    }

    // Displays the final score for Math
    cout << "\nYour final score is: " << scoreMath << " out of " << selectedIndices.size() << ".\n";

}


// Category Function to handle category selection and question display
void CategoryFunction(){
    
    int category; // Variable to store user's input of category of choice

            cout << "Enter the number of your choice (1-3): ";
            cin >> category; 

            // Switch case to handle different categories
            switch (category) {
                case 1:
                    cout << "\nYou chose Discrete Structures I!" << endl;
                    cout << "\nWelcome to the Discrete Structures I Category! For the mechanics, type a letter for the correct answer.\n" << endl;
                    
                    questionsDiscrete(); // Calls the Discrete Structures Questions Function

                    break;

                case 2:
                    cout << "\nYou chose English Literature!" << endl;
                    questionsEnglishLiterature(); // Calls the English Literature Questions Function

                    break;

                case 3:
                    cout << "\nYou chose Mathematics!" << endl;
                    cout << "\nWelcome to the Mathematics Category! For the mechanics, type a letter for the correct answer.\n" << endl;

                    questionsMath(); // Calls the Math Questions Function

                    break;
                    
                default:
                    cout << "Invalid category choice. Exiting the program." << endl;
                    exit(0); // Exits if the conditions do not match the user's input
            }
            
}


// Main Function

int main(){

    char choice; // Variable to store user's choice to play
    string yourName; // Variable to store user's name (first or full name)
    bool playAgain = true; // Flags to control the game loop
    
    cout << "Please input your name here: ";
    getline (cin, yourName); // Get's the user's name

    cout << "\nWelcome to the Quiz Game, " << yourName <<"! Do you want to play?" << "\nType Y for yes or N for no: " ;
    
    cin >> choice;

    // Main game loop
    while (playAgain) {

        // Sets the condition if user's want to play
        if ( (choice == 'Y') || (choice == 'y') ){
            
            cout << "\nHello, " << yourName << "! Choose a category: " << endl;
            cout << "1. Discrete Structures I" << endl;
            cout << "2. English Literature" << endl;
            cout << "3. Mathematics" << endl;
            
            
            CategoryFunction(); // calls the Category Function
            

            char playAgainChoice; // Variable to store user's choice to play again
            bool playAgainInput = false; // Flag for valid input
            
            // Loop for asking if the user wants to play again
            while (!playAgainInput) {
                cout << "\nDo you want to play again? (Y/N): ";
                cin >> playAgainChoice; 

                
                // Checks is the user wants to exit
                if ((playAgainChoice == 'N') || (playAgainChoice == 'n')){
                    playAgain = false;
                    cout << "Thank you very much for playing! Program Closing...";
                    exit(0); // exits the game
    
                } else if ((playAgainChoice == 'Y') || (playAgainChoice == 'y')){
                    
                    playAgainInput = true; // continue the game
                } else {
                    cout << "Invalid output. Please try again."; // Prompt for valid input
                }
            
            }



        } else if ( (choice == 'N') || (choice == 'n') ) {

            cout << "Okay, exiting the program!";
            exit(0); // Exit if the user chooses not to play

        } else {

            cout << "Invalid input. Program closing.. ";
            exit(0); // Program stop if the user puts an invalid input
            
        }

    }

    
    
return 0; // Return success

}
