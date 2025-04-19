#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

string username, password;
string un, pw;

bool isValidUsername(const string &username) {
    for (char ch : username) {
        if (!isalpha(ch)) {
            return false; // not a letter
        }
    }
    return true;
}

bool isValidPassword(const string &password) {
    return password.length() == 8; // Password should be exactly 8 characters long
}

bool isLoggedIn(const string &username, const string &password) {
    ifstream read(username + ".txt");
    if (!read) {
        return false; // File doesn't exist, so login failed
    }
    getline(read, un);  // Read username
    getline(read, pw);  // Read password
    return (un == username && pw == password); // Check if both match
}

class Quiz {
private:
    struct Question {
        string questionText;
        string options[4]; // Options for the multiple-choice question
        int correctAnswerIndex; // The index of the correct answer
    };

    vector<Question> questions;

public:
    void addQuestion(const string &qText, const string options[], int correctAnswerIndex) {
        Question q;
        q.questionText = qText;
        for (int i = 0; i < 4; ++i) {
            q.options[i] = options[i];
        }
        q.correctAnswerIndex = correctAnswerIndex;
        questions.push_back(q);
    }

    int askQuestions() {
        int score = 0;
        for (size_t i = 0; i < questions.size(); ++i) {
            cout << "Question " << i + 1 << ": " << questions[i].questionText << endl;
            for (int j = 0; j < 4; ++j) {
                cout << j + 1 << ". " << questions[i].options[j] << endl;
            }

            int userAnswer;
            cout << "Enter your answer (1-4): ";
            cin >> userAnswer;

            if (userAnswer == questions[i].correctAnswerIndex + 1) {
                cout << "Correct!" << endl;
                score++;
            } else {
                cout << "Wrong! The correct answer was: " << questions[i].options[questions[i].correctAnswerIndex] << endl;
            }
            cout << endl;
        }
        return score;
    }
};

void createTechnicalQuiz(Quiz &quiz) {
    string options[4];
    options[0] = "Java";
    options[1] = "Python";
    options[2] = "C++";
    options[3] = "Ruby";
    quiz.addQuestion("Which programming language is considered a low-level programming language?", options, 2);
    
    options[0] = "Object-Oriented Programming";
    options[1] = "Procedural Programming";
    options[2] = "Functional Programming";
    options[3] = "Logic Programming";
    quiz.addQuestion("C++ programming language is known as?", options, 0);

    options[0] = "int";
    options[1] = "char";
    options[2] = "float";
    options[3] = "boolean";
    quiz.addQuestion("What data type is used to store integer values in C++?", options, 0);

    options[0] = "void";
    options[1] = "main()";
    options[2] = "int";
    options[3] = "return";
    quiz.addQuestion("Which of the following is the starting point of a C++ program?", options, 1);

    options[0] = "cin";
    options[1] = "cout";
    options[2] = "printf";
    options[3] = "scanf";
    quiz.addQuestion("Which command is used for output in C++?", options, 1);

    options[0] = "if-else";
    options[1] = "switch";
    options[2] = "while";
    options[3] = "for";
    quiz.addQuestion("Which control statement is used for decision making?", options, 0);

    options[0] = "class";
    options[1] = "function";
    options[2] = "method";
    options[3] = "module";
    quiz.addQuestion("Which keyword is used to define a class in C++?", options, 0);

    options[0] = "public";
    options[1] = "private";
    options[2] = "protected";
    options[3] = "friend";
    quiz.addQuestion("Which access modifier makes members accessible from outside the class?", options, 0);

    options[0] = "new";
    options[1] = "malloc";
    options[2] = "alloc";
    options[3] = "create";
    quiz.addQuestion("Which function is used to dynamically allocate memory in C++?", options, 1);

    options[0] = "A constructor is called when an object is created.";
    options[1] = "A constructor is called when an object is destroyed.";
    options[2] = "A constructor is a private method.";
    options[3] = "A constructor can return a value.";
    quiz.addQuestion("Which of the following is true about constructors?", options, 0);
}

void createGrammarQuiz(Quiz &quiz) {
    string options[4];

    options[0] = "a large letter";
    options[1] = "A capital letter";
    options[2] = "small letter";
    options[3] = "alphabet";
    quiz.addQuestion("The first letter of the first word in a sentence should be", options, 1);

    options[0] = "or";
    options[1] = "and";
    options[2] = "but";
    options[3] = "so";
    quiz.addQuestion("She plays the piano _____ her brother sings.", options, 1);

    options[0] = "sad";
    options[1] = "joyful";
    options[2] = "tired";
    options[3] = "angry";
    quiz.addQuestion("Which word is a synonym for happy?", options, 1);

    options[0] = "Children";
    options[1] = "Childs";
    options[2] = "Childer";
    options[3] = "Childes";
    quiz.addQuestion("What is the Plural form of Child?", options, 0);

    options[0] = "rise";
    options[1] = "rises";
    options[2] = "rising";
    options[3] = "rosen";
    quiz.addQuestion("The sun _____ in the east.", options, 1);

    options[0] = "gone";
    options[1] = "go";
    options[2] = "went";
    options[3] = "goes";
    quiz.addQuestion("He _____ to the gym yesterday.", options, 2);

    options[0] = "is";
    options[1] = "am";
    options[2] = "be";
    options[3] = "are";
    quiz.addQuestion("My brother and I _____ going to the zoo tomorrow.", options, 3);

    options[0] = "fast";
    options[1] = "house";
    options[2] = "quickly";
    options[3] = "jump";
    quiz.addQuestion("Which of the following is an exampple of adverb?", options, 2);

    options[0] = "leafs";
    options[1] = "leaves";
    options[2] = "leafes";
    options[3] = "leave";
    quiz.addQuestion("What is the plural form of leaf?", options, 1);

    options[0] = "House";
    options[1] = "Quickly";
    options[2] = "And";
    options[3] = "Under";
    quiz.addQuestion("In following options which word is a conjunction?", options, 2);
}
void createGeneralKnowledgeQuiz(Quiz &quiz) {
    string options[4];

    options[0] = "China";
    options[1] = "Japan";
    options[2] = "United States";
    options[3] = "India";
    quiz.addQuestion("Which country is NO.1 in technology?", options, 1);

    options[0] = "C.V. Raman";
    options[1] = "Steve Henry";
    options[2] = "Milan";
    options[3] = "Bill Gates";
    quiz.addQuestion("Who is the founder of Microsoft?", options, 3);

    options[0] = "Chirst Lamb";
    options[1] = "Larry Ellison";
    options[2] = "James Carter";
    options[3] = "Henry Smith";
    quiz.addQuestion("Who is the founder of Oracle?", options, 1);

    options[0] = "Steve Job";
    options[1] = "Jackson Henry";
    options[2] = "Phil Hunghes";
    options[3] = "Simpson";
    quiz.addQuestion("Who is the founder of Apple?", options, 0);

    options[0] = "Charles Babbage";
    options[1] = "Ladies Finger";
    options[2] = "Tomato Finger";
    options[3] = "Charles Angel";
    quiz.addQuestion("Who is the father of computer science?", options, 0);

    options[0] = "Henry-Packard";
    options[1] = "Henry-Packer";
    options[2] = "Hewlett-Packard";
    options[3] = "Helson Packson";
    quiz.addQuestion("What does HP stands for?", options, 2);

    options[0] = "Bill Gates";
    options[1] = "Douglas Engelbart";
    options[2] = "Charles Babbage";
    options[3] = "Christopher Sholes";
    quiz.addQuestion("Who invented mouse?", options, 1);

    options[0] = "International Business Machines";
    options[1] = "International Business Model";
    options[2] = "Integrated Business model";
    options[3] = "Industry Business Model";
    quiz.addQuestion("What does the IBM stands for?", options, 0);

    options[0] = "Assembly level language";
    options[1] = "High level language";
    options[2] = "low- level language";
    options[3] = "hybrid level language";
    quiz.addQuestion("What type of programming language is PERL?", options, 1);

    options[0] = "Java 2 Enterprise Edition";
    options[1] = "Java 2 Eight Edition";
    options[2] = "Java 2 Eclispse Edition";
    options[3] = "None of the above";
    quiz.addQuestion("What does J2EE stands for?", options, 2);
}
void createSportsQuiz(Quiz &quiz) {
    string options[4];

    options[0] = "Gold";
    options[1] = "Bronze";
    options[2] = "Silver";
    options[3] = "None of these";
    quiz.addQuestion("Which medal won by Swapnil Kusale in Paris Olympics 2024?", options, 1);

    options[0] = "Shooting";
    options[1] = "Badminton";
    options[2] = "Criket";
    options[3] = "Hockey";
    quiz.addQuestion("In which sport does Manu Bhaker excel?", options, 0);

    options[0] = "Padma shri Award";
    options[1] = "Arjuna Award";
    options[2] = "Major Dhyanchand Khel Ratna Award";
    options[3] = "None of the above";
    quiz.addQuestion("Which Award was received by Neeraj Chopra in 2021", options, 2);

    options[0] = "29th August";
    options[1] = "1st June";
    options[2] = "30th March";
    options[3] = "4th July";
    quiz.addQuestion("When is national sports day celebrated in India", options, 0);

    options[0] = "Criket";
    options[1] = "Kho-Kho";
    options[2] = "Hockey";
    options[3] = "Football";
    quiz.addQuestion("Which is the national sport of India?", options, 2);

    options[0] = "15th";
    options[1] = "20th";
    options[2] = "12th";
    options[3] = "18th";
    quiz.addQuestion("Which season of IPL is held in 2025?", options, 3);

    options[0] = "Kho-Kho";
    options[1] = "Criket";
    options[2] = "Football";
    options[3] = "Hockey";
    quiz.addQuestion("Rohit Sharma is related to which sport?", options, 1);

    options[0] = "Kapil Dev";
    options[1] = "Sunil Gavaskar";
    options[2] = "Sachin Tendulkar";
    options[3] = "Virat Kohli";
    quiz.addQuestion("Who Captained India to its first-ever Criket worldcup victory in 1983?", options, 0);

    options[0] = "Rohit Sharma";
    options[1] = "Sachin Tendulkar";
    options[2] = "Sunil Gavaskar";
    options[3] = "Kapil Dev";
    quiz.addQuestion("Who was the first Indian Criketer who scored a double century in ODI?", options, 1);

    options[0] = "P.T. Usha";
    options[1] = "Manoj Tiwari";
    options[2] = "Milka Singh";
    options[3] = "Neeraj Chopra";
    quiz.addQuestion("Which Indian Athlete is konwn as the'Flying Sikh' for his eceptional speed in atheletics?", options, 2);
}
void createScienceandNatureQuiz(Quiz &quiz) {
    string options[4];

    options[0] = "1st March";
    options[1] = "28th February";
    options[2] = "3rd June";
    options[3] = "19 February";
    quiz.addQuestion("On which day National Science Day is celebrated in India?", options, 1);

    options[0] = "80";
    options[1] = "79";
    options[2] = "69";
    options[3] = "34";
    quiz.addQuestion("What is the atomic number of Gold?", options, 1);

    options[0] = "Oxidation";
    options[1] = "Transpiration";
    options[2] = "Respiration";
    options[3] = "Photosynthesis";
    quiz.addQuestion("Which of the following process is responcible for the green colour of plants?", options, 3);

    options[0] = "Frog";
    options[1] = "Fish";
    options[2] = "Dog";
    options[3] = "Cat";
    quiz.addQuestion("Which animal breathes threw skin?", options, 0);

    options[0] = "Oceans";
    options[1] = "Volcanoes";
    options[2] = "The Sun";
    options[3] = "Moon";
    quiz.addQuestion("What is the main source of energy for life on Earth?", options, 2);

    options[0] = "Oxygen";
    options[1] = "Hydrogen";
    options[2] = "Nitrogen";
    options[3] = "Carbon dioxide";
    quiz.addQuestion("Which gas do plants takes during Photosynthesis?", options, 3);

    options[0] = "Electrical Energy";
    options[1] = "Chemical Energy";
    options[2] = "Thermal Energy";
    options[3] = "Light Energy";
    quiz.addQuestion("What type of energy stored in food?", options, 1);

    options[0] = "Newton";
    options[1] = "Kilo meter";
    options[2] = "Seconds";
    options[3] = "Joule";
    quiz.addQuestion("What is unit of force in Physics?", options, 0);

    options[0] = "2-8";
    options[1] = "6.5-7.5";
    options[2] = "9-10";
    options[3] = "4.5-5.5";
    quiz.addQuestion("What is the idele pH range for the most fresh water aquariums?", options, 1);

    options[0] = "6";
    options[1] = "8";
    options[2] = "7";
    options[3] = "9";
    quiz.addQuestion("How many colours are there in rainbow?", options, 2);
    // Add more questions similarly...
}

void createRegistrationPage() {
    cout << "                                         Registration:                                             " << endl;
    cout << "Enter Username (letters only): ";
    cin >> username;
    cout << "Enter Password (8 digit characters or numbers only): ";
    cin >> password;

    if (!isValidUsername(username)) {
        cout << "Invalid username! Only letters are allowed." << endl;
    } else if (!isValidPassword(password)) {
        cout << "Invalid password! It must be exactly 8 characters long." << endl;
    } else {
        cout << "Username and password are valid." << endl;
    }

    // Save to file
    ofstream file(username + ".txt");
    file << username << endl << password;
    file.close();
    cout << "*************************************Welcome " << username << "!!!************************************" << endl;
}

void createLoginPage() {
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (isLoggedIn(username, password)) {
        cout << "Login Successful!" << endl;
    } else {
        cout << "Login Failed! Invalid username or password." << endl;
    }
}
int main() {
    Quiz technicalQuiz;
    createTechnicalQuiz(technicalQuiz);
    Quiz grammarQuiz;
    createGrammarQuiz(grammarQuiz);
    Quiz generalKnowledgeQuiz;
    createGeneralKnowledgeQuiz(generalKnowledgeQuiz);
    Quiz sportsQuiz;
    createSportsQuiz(sportsQuiz);
    Quiz scienceQuiz;
    createScienceandNatureQuiz(scienceQuiz);

    int mainChoice;
    while (true) {
        cout << "\n******************************************** Main Menu ********************************************" << endl;
        cout << "1. Register\n2. Login\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> mainChoice;

        if (mainChoice == 1) {
            createRegistrationPage();
        } else if (mainChoice == 2) {
            createLoginPage();
            if (isLoggedIn(username, password)) {
                int quizChoice;
                while (true) {
                    cout << "\nSelect a Quiz Category:\n";
                    cout << "1. Technical\n2. Grammar\n3. General Knowledge\n4. Sports\n5. Science and Nature\n6. Logout\n";
                    cout << "Enter your choice: ";
                    cin >> quizChoice;

                    int score = 0;
                    switch (quizChoice) {
                        case 1:
                            score = technicalQuiz.askQuestions();
                            break;
                        case 2:
                            score = grammarQuiz.askQuestions();
                            break;
                        case 3:
                            score = generalKnowledgeQuiz.askQuestions();
                            break;
                        case 4:
                            score = sportsQuiz.askQuestions();
                            break;
                        case 5:
                            score = scienceQuiz.askQuestions();
                            break;
                        case 6:
                            cout << "Logging out...\n";
                            goto mainMenu; // jump back to main menu
                        default:
                            cout << "Invalid choice.\n";
                            continue;
                    }
                    cout << "Your score: " << score << "/" << 10 << "\n";
                }
            }
        } else if (mainChoice == 3) {
            cout << "Exiting the application. Goodbye!\n";
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
        mainMenu:;
    }
    return 0;
}
