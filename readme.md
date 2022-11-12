# Project: Valet Parking Application

## Latest Release
**Milestone 3** 

### Milestones

|Milestone| Revision | Overview | Comments |
|------|:---:|:----|:----| 
| [MS1](#milestone-1) | V1.0 | [Watch](https://youtu.be/NsQK5V7hQN0)|  |
|  | V1.1 | [clear()](#clear-function) | Added description to what clear function does |
| [MS2](#milestone-2) | V1.0 | [Watch](https://youtu.be/P1ZU2qF1IDU) |  |
|  | V1.1 | [Find Vehicle](#find-vehicle) | Added Find Vehicle description  |
| [MS3](#milestone-3) | V1.0 |  |  |


Your task for the project for this semester is to create an application that keeps track of a Valet Parking that can park Cars and Motorcycles in a parking and retrieve them back when requested. 

## Milestones due dates
This project will be done in 5 milestones and each milestone will have its due date. The due date of each milestone is stated below, and it is based on the amount of work to be done for that milestone. 

## Final project mark and due dates

|Milestone| Mark | Due date | Submission Policy|
|:------:|:---:|:---:|-------|
| MS1 | 10% | Nov 8th | gets full mark even if 1 week late. gets 0% afterwards|
| MS2 | 10% | Nov 13th | gets full mark even if 1 week late. gets 0% afterwards|
| MS3 | 10% | Nov 19th | gets full mark even if 1 week late. gets 0% afterwards|
| MS4 | 10% | Dec 1st  | gets full mark even if 1 week late. gets 0% afterwards|
| MS5 | 60% | Dec 9th  | See below|

> To make the final submission of the project easier and to make it possible to partially submit a project we have divided the submission of milestone 5 into six small ones. Each submission is worth 10% of the project mark. Your project will be marked only if you have all four milestones and at least have one of the 6 six submissions of milestone 5. 

|Milestone 5<br/> Divided into<br/>Six submission| Mark | Due date | Submission Policy|
|:------|:---:|:---:|-------|
| m51 (Load and Save) | 10% | Dec 9th| 10% penalty for each day being late up to 5 days|
| m52 (Park Vehicle) | 10% | Dec 9th| 10% penalty for each day being late up to 5 days|
| m53 (Return Vehicle) | 10% | Dec 9th| 10% penalty for each day being late up to 5 days|
| m54 (List Parked Vehicles) | 10% | Dec 9th| 10% penalty for each day being late up to 5 days|
| m55 (Find Vehicle) | 10% | Dec 9th| 10% penalty for each day being late up to 5 days|
| m56 (Close Parking) | 10% | Dec 9th| 10% penalty for each day being late up to 5 days|

> The first 4 milestones will not be marked based on the code, but their success and their timely submissions. You may modify or debug your previous code as you are going through the milestones. The only milestone that is going to scrutinized based your code will be milestone 5. If you require any feedback on your first four milestones you need to ask your professor to do so.


> :warning: Your project will receive a mark of zero if any of the first 4 milestones are not submitted by the rejection date (Dec 14th 2022 )<br />For your project to be marked, you must submit all the 4 milestones and at least one of the 6 submissions of Milestone 5 (Rejection date for milestone 5 is also Dec 14th 2022)

You can check the due date of each milestone using the ```-due``` flag in the submission command:
```bash
~profname.proflastname/submit 2??/prj/m? -due
```
- replace **2??** with the subject code
- replace **m?** with the milestone number
> Different sections may have different due dates based on their section's progress. Always check the due date using this command. The due date returned by this command always have priority over the due dates stated above.
## Citation, Sources

When submitting your work, all the files submitted should carry full student information along with the "citation and sources" information. See the following example:

If you have multiple submissions of the same milestone, please update the Revision History in each submission so your professor knows what changes to look for.

```C++
/* Citation and Sources...
Final Project Milestone ? 
Module: Whatever
Filename: Whatever.cpp
Version 1.0
Author	John Doe
Revision History
-----------------------------------------------------------
Date      Reason
2020/?/?  Preliminary release
2020/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my project milestones.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and 
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
```

**Failing to include the above citation to any of the files containing your work will cause the rejection of your project submission**

#### See below for details:

### For work that is done entirely by you (ONLY YOU)

If the file contains only your work or the work provided to you by your professor, add the following message as a comment at the top of the file:

> I have done all the coding by myself and only copied the code that my professor provided to complete my project milestones.

### For work that is done partially by you.

If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which part of the assignment is given to you as help, who gave it to you, or which source you received it from.**  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrongdoing.


> :warning: This [Submission Policy](#submission-policy) only applies to the project. All other assessments in this subject have their own submission policies.

### If you have helped someone with your code

If you have helped someone with your code. Let them know of these regulations and in an email write exactly which part of your code was copied and who was the recipient of this code.<br />By doing this you will be clear of any wrongdoing if the recipient of the code does not honour these regulations.

## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
g++ -Wall -std=c++11 -g -o ms file1.cpp file2.cpp ...
```

- `-Wall`: the compiler will report all warnings
- `-std=c++11`: the code will be compiled using the C++11 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ms`: the compiled application will be named `ms`

After compiling and testing your code, run your program as follows to check for possible memory leaks (assuming your executable name is `ms`):

```bash
valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ms
```

- `--show-error-list=yes`: show the list of detected errors
- `--leak-check=full`: check for all types of memory problems
- `--show-leak-kinds=all`: show all types of memory leaks identified (enabled by the previous flag)
- `--track-origins=yes`: tracks the origin of uninitialized values (`g++` must use `-g` flag for compilation, so the information displayed here is meaningful).

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.


### Adding alias to `.bash_profile` on matrix
You can add the following two lines to the end of your `.bash_profile` file in your matrix home directory to create two aliases for the above C++ compilation and valgrind testing so you don't have to type such a long command to compile and execute your programs:
```bash
alias msc++="g++ -Wall -std=c++11 -g -o ms"
alias vrun="valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all --track-origins=yes"
```
By adding the above to the '.bash_profile' (you must logoff and log back it so it takes effect) you can compile your c++ files as follows:
```bash
msc++ file1.cpp file2.cpp file3.cpp...<ENTER>
```
The above will compile your files and if successful it will create an executable called `ms`.
```bash
vrun ms<ENTER>
```
The above will execute your `ms` executable under the tester `valgrind` for detailed test on leaks and runtime errors.

> Note: All the code written in this project must be implemented in the **sdds** namespace, unless instructed otherwise.

> Make sure that all the debugging code and debugging comments are removed before submission.

## Project Implementation notes:  *Very Important, read carefully*
- All the code written in this project should be within the namespace sdds.

- You are free and encouraged to add any attributes(member variables), functions and methods (member functions) you find necessary to complete your code. If you are not sure about your strategy for adding functionalities and properties to your classes, ask your professor for advice.  

- If any methods are being added and they are not called outside the scope of the class, make sure they are private.

- Unless you are asked for a specific definition, name the variables, and functions yourself. Use proper names and follow the naming conventions instructed by your professor. Having meaningless and misleading names will attract a penalty.

- When creating methods (member functions) make sure to make them constant if in their logic, they are not modifying their class.

- When passing an object or variable by address or reference, if they are not to be modified, make sure they are passed as constant pointers and references.

- If an Empty state is required for an object, it is considered to be an “invalid” empty state, and objects in this state should be rendered unusable.

- A module called **Utils** is added to the project that can be used for your custom functions and classes in your implementation. Leave this module empty if you don't have any custom functionalities. <br />
You can add any custom code/class of your own to the **Utils** module to be used throughout the project. 

- Throughout the project, if any class is capable of displaying or writing itself, the member function will always have the following signature: 
The function will return a reference of an **ostream** and will receive a reference on an **ostream** as an optional argument. If this argument is not provided, the object “**cout**” will be passed instead. 

- Throughout the project, if any class is capable of reading or receiving its content from a stream, the member function will always have the following signature: 
The function will return a reference of an **istream** and will receive a reference on an **istream** as an optional argument. If this argument is not provided, the object “**cin**” will be passed instead. 

- When passing an object or variable by address or reference, if they are not to be modified, make sure they are passed as constant pointers and references.

- You may reuse and copy any code your professor provided for your workshops or functions you may have from previous work in this subject or other subjects and place it in the Utils module. 

# The Project; Valet Parking Application

We will start the development of the project by creating its user interface (MS1, Menu system). Then we will create a mockup application that represents what the application will look like and act without actually doing anything(MS2 Parking app). In short, we are creating a prototype of the application (in ms1 and ms2) then coding its engine (in ms3 and ms4) and finally adding functionality to Parking (ms2) to make it fully functional (in ms5).

# Milestone 1
## The Menu Module

This Module contains two classes; MenuItem and Menu. MenuItem is a fully private class owned by the Menu Class (Menu is a friend of MenuItem). Therfore, Only the Menu class can construct and use the MenuItem and because of this the two classes reside in the same module.

## Purpose:

Menu displays a menu title and several menu items with a row number attached to each, and lets the user make a selection. After user makes the selection, the row number of the selected menu item is returned to the caller program. 

## The MenuItem class:

Create a fully private class (no public members) called MenuItem that is owned by the Menu class. (i.e. Menu is a friend of MenuItem).

To make this possible (since Menu is not yet implemented), forward declare the Menu class to be able to make it a friend of MenuItem class.

MenuItem can hold a C-style character string with a maximum length of 50 as its content. Any attempt to set the content to more than 50 characters should store the truncated value instead (down to 50 characters). 

### Construction:

Menuitem can be created by a constant C-style character string to be used to set its content. If the provided string is invalid (null) then the object is set to an Empty state. 

### Member function:
The MenuItem can display itself by writing its content on the screen and printing a new line. 

If MenuItem is in an empty state, nothing is printed. 

### Copy and Assignment:
MenuItem can not get copied or assigned to another MenuItem. This, must be enforced in your code.

### Other member functions:
Add other members to MenuItem if needed during the development of this module 

 
## The Menu class:
Before starting to implement the Menu class, create a constant int value in the Menu module called MAX_NO_OF_ITEMS and set it to 10. 

## Properties: (member variables)
### Title:
Menu can hold a C-style character string with a maximum length of 50 as its title. Any attempt to set the content to more than 50 characters should store the truncated value instead (down to 50 characters). 

### MenuItems: 
The Menu class holds an array of MenuItems with a size of MAX_NO_OF_ITEMS. Throughout the program, as menu items are added to the Menu, the elements of the array are set to individual MenuItems for each addition. 

Make sure you keep track of the number of added MenuItems to the Menu for printing the Menu and item selection validation.

### Indentation: 

When displaying the menu, the title and menu items may be indented to the right. For each indentation level (value of 1) indent the menu 4 spaces to the right. (You can keep this value in an integer attribute)

Menu example without indentation (value of 0):
```text
** The Menu **
1- Option one
2- Option Two
3- Option three
4- Option four
5- Exit
>
```
Menu example with indentation value of 2:
```text
        ** The Menu **
        1- Option one
        2- Option Two
        3- Option three
        4- Option four
        5- Exit
        >
```

### Other properties: 
Add other properties if or when needed. 

### Construction:
A Menu object can be created by a constant C-style character string, to be used to set its title and an optional integer value for indentation. If indentation is not provided, the value “0” will be passed instead.

If the string is invalid (null) then Menu is set to an invalid empty state.

### Copy and Assignment:
Menu can not get copied or assigned to another Menu. This, must be enforced in your code.

### Member functions, operator and cast overloads:

#### bool cast overload
Overload the cast operator so if the Menu object is casted to a bool, it returns true if the Menu is valid and usable, otherwise it returns false if the Menu is in an invalid empty state.

#### isEmpty() function
Write an isEmpty function that returns true if the Menu is in an invalid empty State or false if it is valid and usable.

Note that isEmpty works the opposite of the bool cast overload.

#### display function
The Menu should display itself as follows:

If the Menu is in an invalid empty state, it will print: ```"Invalid Menu!"``` and a new line

If the Menu has no MenuItems, it will print: ```"No Items to display!"``` and a new line

##### Otherwise:

First it will print its title and go to new line.<br />
Then it will display a row number, starting with number one (1) and a dash.<br />
Afterwards it will print a space and then the first MenuItem in the array. <br />
It will continue printing the row numbers and the MenuItems to the number of menu items added to the Menu.<br /> 
At end it will print a greater-than operator (“>”) and a space as the prompt for user selection. 
##### Menu example:
```text
** The Menu **
1- Option one
2- Option Two
3- Option three
4- Option four
5- Exit
> 
```
#### Assignment 
A Menu should be able to be assigned to a constant character C-string. This should reset the title of the Menu to the newly assigned string. If the string is invalid (null) the Menu is set to an invalid empty state.

##### Assignment example:
```C++
Menu lunchMenu("Lunch Menu");
lunchMenu = "New Title"; //<<---- Assignment
```

#### add function: 
write an add function that returns nothing and receives a constant character C-string to build a MenuItem and add it to the MenuItems of the Menu. 

If the string is invalid (null) then the Menu is set to an invalid empty state and nothing is added.

The add function should use the C-string argument to add a MenuItem to the Menu if possible. 

If the MenuItem array is full, then the function should silently ignore the addition and exit. Also, the add function will do nothing and exit silently if the Menu is in an invalid empty state.

#### clear function
This function removes all the menu items and the title and therefore sets the menu to an empty menu.

#### left shift operator overload (“<<”)
Overload the left shift operator to insert a constant character C-string into the Menu as a MenuItem. This overload should work exactly like the add function and work as follows: 

Insertion example to add three MenuItems to the lunchMenu:
```C++
Menu lunchMenu("Lunch Menu");
lunchMenu << "Hamburger" << "Chicken Sandwich" << "Pasta and meatballs";
```

Displaying the above menu should result the following:

```text
Lunch Menu
1- Hamburger
2- Chicken Sandwich
3- Pasta and meatballs
> 
```

Insertion example to add invalid MenuItems to the lunchMenu:
```text
Menu lunchMenu("Lunch Menu");
lunchMenu << nullptr << "Chicken Sandwich" << "Pasta and meatballs";
```
Displaying the above menu should result the following:
```text
Invalid Menu!
```

#### Menu class in action (run function):
Create a function called run that returns an integer. In this function displays the Menu and waits for the user’s response to select an option by entering the row number of the MenuItems. 

If the user enters non-integer value print the following error message: ```"Invalid Integer, try again: "```
 and wait for the user’s response.

If the user enters an integer, but out of the boundary of the available options print the following error message: ```"Invalid selection, try again: "``` and wait for the user’s response.

When user selects a valid option, end the function and return the selected option value.

If the Menu has no MenuItems, no selection is made and 0 returned with no user interaction.

Run function example:

```C++
Menu lunchMenu("Lunch Menu");
lunchMenu << "Hamburger" << "Chicken Sandwich" << "Pasta and meatballs";
int choice = lunchMenu.run();
cout << "You selected " << choice << endl;
```
### Integer cast overload
After creating the run function, overload the cast operator so if the Menu object is casted to an integer, the run function is called, and its value is returned as the integer cast value. 

Integer cast example:
```C++
Menu lunchMenu("Lunch Menu");
lunchMenu << "Hamburger" << "Chicken Sandwich" << "Pasta and meatballs";
int choice = lunchMenu;
cout << "You selected " << choice << endl;
```
#### Other member functions:
Add other member functions to the Menu if needed.


## MS1 Tester program

Write your own tester or use the following tester program to test and debug your Date class.

```C++
/* ------------------------------------------------------
Final Project Milestone 1
Module: Menu
Filename: main.cpp
Version 1.0
Author	Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------*/

#include <iostream>
#include "Utils.h"
#include "Menu.h"
using namespace std;
using namespace sdds;
int showSelection(int n);
void prompt(const char* message);
void pause();
void testMenus(const Menu& m, const Menu& sub1, const Menu& sub2);
void TT(const char* title);
int main() {
   TT("M1T1: constructors");
   Menu mainMenu("** Main Menu **");
   Menu subMenu1("** Sub Menu One **", 1);
   Menu subMenu2("** Sub Menu **", 2);
   Menu tempMenu("** Temp **");
   Menu invMenu("** To test Invalid Menu **");

   TT("M1T2: operator<< adding MenuItems");
   tempMenu << "One" << "Two" << "three";

 

   TT("M1T3: Menu::run()");
   prompt("Do the following: \nabc <ENTER>\n0 <ENTER>\n4 <ENTER>\n3 <ENTER>");
   cout << tempMenu.run() << " selected!" << endl;
   pause();


   TT("M1T4: Reseting Menu title and running an empty menu with no Items");
   tempMenu.clear();
   tempMenu = "** New Title **"; //<<---- Assignment
   cout << tempMenu.run() << " returned by the Menu with no Items." << endl;
   pause();

   TT("M1T5: Menu::add() and operator<<");
   mainMenu.add("Option one");
   mainMenu.add("Option Two");
   mainMenu.add("Sub Options");
   mainMenu.add("Option four");
   mainMenu.add("Exit");
   subMenu1 << "Selection one" << "Sub Selections two" << "Selection three" << "Selection four";
   subMenu2 << "The first" << "The second" << "The third";



   TT("M1T6: Submenu and indentation display");
   testMenus(mainMenu, subMenu1, subMenu2);

   TT("M1T7: operator bool()");
   if (mainMenu) {
      cout << "The mainMenu is valid and usable." << endl;
   }

   TT("M1T8: Invalid Menu and its usage");
   mainMenu.add(nullptr);
   if (!mainMenu) {
      cout << "The mainMenu is invalid(empty) and not usable." << endl;
   }
   mainMenu.run();
   mainMenu.display();
   
   TT("M1T9: Adding invalid string to render Menu invalid");
   invMenu << nullptr << "This should not be added" << "This shouldn't be added either";
   invMenu.run();
   invMenu.display();
   return 0;
}
int showSelection(int n) {
   cout << "You selected " << n << "." << endl;
   return n;
}

void prompt(const char* message) {
   cout << message << endl;
}
void pause() {
   cout << "Press enter to continue..." << endl;
   cin.ignore(1000, '\n');
}
void testMenus(const Menu& m, const Menu& sub1, const Menu& sub2) {
   int selection;
   prompt("Do the following:\n2 <ENTER>\n3 <ENTER>");
   while ((selection = m.run()) != 5) {
      showSelection(selection);
      if (selection == 3) {
         prompt("Do the following:\n2 <ENTER>");
         if (showSelection(sub1) == 2) {
            prompt("Do the following:\n3 <ENTER>\n5 <ENTER>");
            showSelection(sub2);
         }
      }
   }
}
void TT(const char* title) {
   cout << "******************************************************************" << endl;
   cout << title << endl;
   cout << "==================>" << endl;
}


```

### output sample


```Text
******************************************************************
M1T1: constructors
==================>
******************************************************************
M1T2: operator<< adding MenuItems
==================>
******************************************************************
M1T3: Menu::run()
==================>
Do the following:
abc <ENTER>
0 <ENTER>
4 <ENTER>
3 <ENTER>
** Temp **
1- One
2- Two
3- three
> abc
Invalid Integer, try again: 0
Invalid selection, try again: 4
Invalid selection, try again: 3
3 selected!
Press enter to continue...

******************************************************************
M1T4: Reseting Menu title and running an empty menu with no Items
==================>
** New Title **
No Items to display!
0 returned by the Menu with no Items.
Press enter to continue...

******************************************************************
M1T5: Menu::add() and operator<<
==================>
******************************************************************
M1T6: Submenu and indentation display
==================>
Do the following:
2 <ENTER>
3 <ENTER>
** Main Menu **
1- Option one
2- Option Two
3- Sub Options
4- Option four
5- Exit
> 2
You selected 2.
** Main Menu **
1- Option one
2- Option Two
3- Sub Options
4- Option four
5- Exit
> 3
You selected 3.
Do the following:
2 <ENTER>
    ** Sub Menu One **
    1- Selection one
    2- Sub Selections two
    3- Selection three
    4- Selection four
    > 2
You selected 2.
Do the following:
3 <ENTER>
5 <ENTER>
        ** Sub Menu **
        1- The first
        2- The second
        3- The third
        > 3
You selected 3.
** Main Menu **
1- Option one
2- Option Two
3- Sub Options
4- Option four
5- Exit
> 5
******************************************************************
M1T7: operator bool()
==================>
The mainMenu is valid and usable.
******************************************************************
M1T8: Invalid Menu and its usage
==================>
The mainMenu is invalid(empty) and not usable.
Invalid Menu!
Invalid Menu!
******************************************************************
M1T9: Adding invalid string to render Menu invalid
==================>
Invalid Menu!
Invalid Menu!

```


## MS1 Submission 

> If you would like to successfully complete the project and be on time, **start early** and try to meet all the due dates of the milestones.

Upload your source code and the tester program to your `matrix` account. Compile and run your code using the `g++` compiler [as shown in the introduction](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 2??/prj/m1
```
and follow the instructions.

- *2??* is replaced with your subject code


### The submit program's options:
```bash
~prof_name.prof_lastname/submit DeliverableName [-submission options]<ENTER>
[-submission option] acceptable values:
  "-due":
       Shows due dates only
       This option cannot be used in combination with any other option.
  "-skip_spaces":
       Do the submission regardless of incorrect horizontal spacing.
       This option may attract penalty.
  "-skip_blank_lines":
       Do the submission regardless of incorrect vertical spacing.
       This option may attract penalty.
  "-feedback":
       Check the program execution without submission.
```

## [Back to milestones](#milestones)

# Milestone 2

## The Parking module:

The parking module is the skeleton of your final project and will be revisited at the final stage of the application development. In milestone 2 you will build the main structure of the application that gives the user all the options needed for managing the Valet Parking. 

For now, when these options are selected you will only print the name of the action. In the following milestones, you will develop the facilities needed to provide the actual requested actions by the user. 

### The Parking module runs as follows:
It loads a data file from the hard disk that holds the information about the parked cars in the Parking. (the actual loading will be implemented in the last milestone) Then it will display the following menu:

```text
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Find Vehicle
5- Close Parking (End of day)
6- Exit Program
>
```
If the user selects the first option, a submenu as follows with one indentation to right will be displayed:

```text
    Select type of the vehicle:
    1- Car
    2- Motorcycle
    3- Cancel
    >
```


### Mock-up messages
For now, print the following messages based on the user's selections:

#### Park Vehicle / Car:

```text
---------------------------------
Parking Car
---------------------------------
```
#### Park Vehicle / Motorcycle:
```text
---------------------------------
Parking Motorcycle
---------------------------------
```
#### Park Vehicle / Cancel:
```text
---------------------------------
Cancelled parking
---------------------------------
```
#### Return Vehicle:
```text
---------------------------------
Returning Vehicle
---------------------------------
```
#### List Parked Vehicles:
```text
---------------------------------
Listing Parked Vehicles
---------------------------------
```
#### Find Vehicle
```text
---------------------------------
Finding a Vehicle
---------------------------------
```
#### Close Parking (End of day):
Selecting this option ends the parking application for the day<br />
If the exit program option is selected first display the message:
```text
This will close the parking; All the vehicles will be removed!
Are you sure? (Y)es/(N)o:
```
And wait for the user to enter either “Y” or “N” (lowercase or uppercase) and exit if the response is yes.

If the user enters an invalid response then print:
```text
Invalid response, only (Y)es or (N)o are acceptable, retry:
```
And repeat until a proper response is entered.

#### Exit Program:

Selecting this option ends the parking application temporarily.<br />
If the exit program option is selected first display the message:
```text
This will terminate the application and save the data!
Are you sure? (Y)es/(N)o:
```
And wait for the user to enter either “Y” or “N” (lowercase or uppercase) and exit if the response is yes.

If the user enters an invalid response then print:
```text
Invalid response, only (Y)es or (N)o are acceptable, retry:
```
And repeat until a proper response is entered.

To accomplish the above Parking module functionality, implement the following:

### The Parking class implementation:
#### Properties: (member variables and objects)
##### Filename:
Parking holds a C-style string with an unknown size to hold the data path and file name of the application. (for example: `"../data/datafile.dat"`)
##### Parking menu: 
Parking has a Menu object for the main menu of the application.

Initialize the Parking Menu with the following (see the constructor for more detail):

- Indentation: `0`
- Parking Menu Title: `"Parking Menu, select an action:"`

And then populate the menu items with the following in the constructor:

```text
"Park Vehicle"
"Return Vehicle"
"List Parked Vehicles"
"Find Vehicle"
"Close Parking (End of day)"
"Exit Program"
```
##### Vehicle Selection menu: 
Parking has a Menu object for the Vehicle selection menu that is displayed as a submenu when option one of the Parking Menu is selected.

Initialize the Vehicle Menu with the following (see the constructor for more detail):

- Indentation: `1`<br />
- Vehicle Menu Title: `"Select type of the vehicle:"`<br />

And then populate the menu items with the following in the constructor

```text
"Car"
"Motorcycle"
"Cancel"
```

##### Other properties: 
Add other properties if, or when needed. 

#### Constructor implementation:
Parking can be created by a constant C-style character string with an unknown size, to be used to set the name of the file and its path. 

If the string is nullptr or empty then Parking is set to an invalid empty state.

Call the Load Data File function (see list of member functions) and if it returns true, then populate the Parking and Vehicle menus. 

If the Load Data File function returns false, then print:

```text
Error in data file<NEWLINE>
```
and set the class to an invalid empty state.
#### Destructor implementation:
- Call the Save Data File function (see list of member functions), and Make sure there is no memory leak when the Parking goes out of scope.

#### Copy and Assignment:
Copy and assignment are denied in the Parking class. (Parking class can not be copied or assigned to another Parking object)

### Private Member function implementations:
For now, these are just mock-up functions that mostly print the messages displayed in the [Mock-up Messages](#mock-up-messages)

#### isEmpty() function
Write an isEmpty function that returns true if the Parking is in an invalid empty State or false if the parking is valid and usable.

#### Parking Status function 
This function does not receive or return anything and at this stage only prints:
```text
****** Valet Parking ******<NEWLINE>
```

#### Park Vehicle function 
This function does not receive or return anything.<br />
The function displays the Vehicle Selection sub-menu. Then based on the user's selection; Car, Motorcycle or Cancel, it will print [the corresponding message](#mock-up-messages). Afterwards, it goes to a new line. 

#### Return Vehicle function 
This function does not receive or return anything and only prints [the corresponding message](#mock-up-messages).

#### List Parked Vehicles function 
This function does not receive or return anything and only prints [the corresponding message](#mock-up-messages).

#### Find Vehicle function 
This function does not receive or return anything and only prints [the corresponding message](#mock-up-messages).

#### Close Parking function 
This function does not receive anything and returns a Boolean.<br />
Follow the instruction in the [Close Parking (End of day)](#close-parking-end-of-day) menu selection and then return true, if the user’s response is Yes. Otherwise, return false if the user’s response is No.

#### Exit Parking App Function 
This function does not receive anything and returns a Boolean.<br />
Follow the instruction in the [Exit program](#exit-program) menu selection and then return true, if the user’s response is Yes. Otherwise, return false if the user’s response is No.

#### Load Data File function 
This function does not receive anything and returns a Boolean.<br />
If the Parking is not in an invalid empty state,  Print the following: `"loading data from "` and then print the name of the data file followed by a `<NEWLINE>` and finally return true.<br />
If the Parking is in an invalid empty state, return false (and print nothing).

#### Save Data File function 
This function does not receive or return anything and if the Parking is not in an invalid empty state it prints:
`"Saving data into "` then prints the name of the data file followed by a `<NEWLINE>`.

### Public Methods

#### int Parking::run(); 

Run is the only public member function in Parking and runs the whole Parking Application exactly as stated in The Parking class overview section using the following functions calls and logic:

If the Parking is not in an invalid empty state:

1. The Run function calls the Parking Status function and then displays the Parking menu and waits for the user’s response.  
2. If any of menu options 1, 2, 3 or 4 are selected, it will call one of the Park Vehicle, Return Vehicle, List Parked Vehicles or findVehicle functions respectively and goes back to step **1**.
3. If menu option 5 is selected it will call the Close Parking function. If the Close Parking Function returns true it will exit and end the Run function. Otherwise, it goes back to step **1**.
4. If menu option 6 is selected it will call the Exit Parking App function and exits the Run function only if a true value is returned. Otherwise, it goes back to step **1**.

When Run exits, it should return 1 if the Parking is in an invalid empty state, otherwise, it should return 0. 

Note: As you see options 5 and 6 can both exit the program. In future implementations, there will be a difference between the two: 

Closing Parking is an end-of-the-day action; which results in towing all the remaining vehicles out of the parking since this is not an overnight parking application.

The Exit Program option acts as a pause in the application execution. In this case, the program (in future implementations) will save all its information in the data file and when it is executed again it will load all the data back and continue where it left off last time. 

### Other member functions:
-	Add other member functions to the Parking if needed.

## Tester program
```C++
/* ------------------------------------------------------
Final Project Milestone 2
Module: Parking
Filename: main.cpp
Version 1.0
Author	Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------*/
#include "Parking.h"
#include <iostream>
using namespace sdds;
int main() {
   Parking P("ParkingData.csv"), bad1(nullptr),bad2("");
   bad1.run();
   bad2.run();
   P.run();
   std::cout << std::endl << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl<<std::endl;
   P.run();
   return 0;
}
```
## Execution output
### data entry
```text
1
1
1
2
1
3
2
3
4
5
a
y
6
N   << this is Capital N
6
a
Y   << this is Capital Y

```
### Output
```text
---------------------------------
loading data from ParkingData.csv
---------------------------------

Error in data file
Error in data file
****** Valet Parking ******
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Find Vehicle
5- Close Parking (End of day)
6- Exit Program
> 1
    Select type of the vehicle:
    1- Car
    2- Motorcycle
    3- Cancel
    > 1
---------------------------------
Parking Car
---------------------------------

****** Valet Parking ******
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Find Vehicle
5- Close Parking (End of day)
6- Exit Program
> 1
    Select type of the vehicle:
    1- Car
    2- Motorcycle
    3- Cancel
    > 2
---------------------------------
Parking Motorcycle
---------------------------------

****** Valet Parking ******
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Find Vehicle
5- Close Parking (End of day)
6- Exit Program
> 1
    Select type of the vehicle:
    1- Car
    2- Motorcycle
    3- Cancel
    > 3
---------------------------------
Cancelled parking
---------------------------------

****** Valet Parking ******
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Find Vehicle
5- Close Parking (End of day)
6- Exit Program
> 2
---------------------------------
Returning Vehicle
---------------------------------

****** Valet Parking ******
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Find Vehicle
5- Close Parking (End of day)
6- Exit Program
> 3
---------------------------------
Listing Parked Vehicles
---------------------------------

****** Valet Parking ******
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Find Vehicle
5- Close Parking (End of day)
6- Exit Program
> 4
---------------------------------
Finding a Vehicle
---------------------------------

****** Valet Parking ******
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Find Vehicle
5- Close Parking (End of day)
6- Exit Program
> 5
This will close the parking; All the vehicles will be removed!
Are you sure? (Y)es/(N)o: a
Invalid response, only (Y)es or (N)o are acceptable, retry: y
Ending application!

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

****** Valet Parking ******
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Find Vehicle
5- Close Parking (End of day)
6- Exit Program
> 6
This will terminate the application and save the data!
Are you sure? (Y)es/(N)o: N
****** Valet Parking ******
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Find Vehicle
5- Close Parking (End of day)
6- Exit Program
> 6
This will terminate the application and save the data!
Are you sure? (Y)es/(N)o: a
Invalid response, only (Y)es or (N)o are acceptable, retry: Y
Exiting application!
---------------------------------
Saving data into ParkingData.csv
---------------------------------
```




## MS2 Submission 

> If you would like to successfully complete the project and be on time, **start early** and try to meet all the due dates of the milestones.

Upload your source code and the tester program to your `matrix` account. Compile and run your code using the `g++` compiler [as shown in the introduction](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 2??/prj/m2
```
and follow the instructions.

- *2??* is replaced with your subject code


### The submit program's options:
```bash
~prof_name.prof_lastname/submit DeliverableName [-submission options]<ENTER>
[-submission option] acceptable values:
  "-due":
       Shows due dates only
       This option cannot be used in combination with any other option.
  "-skip_spaces":
       Do the submission regardless of incorrect horizontal spacing.
       This option may attract penalty.
  "-skip_blank_lines":
       Do the submission regardless of incorrect vertical spacing.
       This option may attract penalty.
  "-feedback":
       Check the program execution without submission.
```

## [Back to milestones](#milestones)

# Milestone 3
## Milestone 3.1
To continue with the project, we need to have an abstract base class to make our future Car and Motorcycle classes read/writable. We call this class ReadWritable

### The ReadWritable module:
Create a class called ReadWritable. ReadWritable class should force Read and Write capability to all its derived classes in two different ways; Comma Separated Values or Screen format. 

### The ReadWritable class implementation:
#### Comma Separated Values flag attribute
Add a bool flag as an attribute for the class to keep the stat of reading or writing the object in Comma Separated mode or not.

#### Other properties: 
Add other properties if, or when needed. 
### Constructor implementation:
- ReadWritable Has only a no-argument constructor that sets the Comma Separated Values flag to false.

### Destructor implementation:
- Create an empty virtual destructor for ReadWritable Class.

### Public Member function implementations:
-	bool isCsv()const;

    This query returns the Comma Separated Values flag;
-	void setCsv(bool value); 

    This function set the Comma Separated Values flag to the incoming bool value.
-	Read and Write 
    
    Create two pure virtual functions to read and write this object in future derived class implementations.
    The read and write function signatures have been described in milestone 1. 
    Helper insertion and extraction operator overloads for istream and ostream:
    
-	Implement the operator<< and operator>> to make any ReadWritable class Writable or Readable using ostream and istream.

### Other member functions:
-	Add other member functions to the ReadWritable class if needed.

## MS3.1 Tester program
Use this tester program to test your ReadWritable implementation. This will be part one of your milestone-3 main tester.

```C++
/* ------------------------------------------------------
Final Project Milestone 3.1
Module: N/A
Filename: RW_Tester.cpp
Version 1.0
Author	Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------*/

#include <iostream>
#include <fstream>
using namespace std;
#include "ReadWritable.h"
using namespace sdds;
class Box :public ReadWritable {
   int m_width;
   int m_height;
public:
   Box(int width = 0, int height = 0) {
      m_width = width;
      m_height = height;
   }
   std::istream& read(std::istream& istr = std::cin) {
      if (isCsv()) {
         istr >> m_width;
         istr.ignore();
         istr >> m_height;
      }
      else {
         cout << "Width: ";
         istr >> m_width;
         cout << "Height: ";
         istr >> m_height;
      }
      return istr;
   }
   std::ostream& write(std::ostream& ostr = std::cout)const {
      if (isCsv()) {
         ostr << m_width << "," << m_height;
      }
      else {
         int i;
         int j; 
         for (cout << "*", i = 0; i < m_width - 1; cout << " *", i++);
         ostr << endl;
         for (j = 0; j < m_height - 2; j++) {
            for (cout << "* ",i = 0; i < m_width - 2; i++, cout << "  ");
            cout << "*" << endl;
         }
         for (cout << "*", i = 0; i < m_width - 1; cout << " *", i++);
      }
      return ostr;
   }
};

void pause();
void test1();
void test2();
void test3();
void test4();
int main() {
   test1();
   pause();
   test2();
   pause();
   test3();
   pause();
   test4();
   return 0;
}

void pause() {
   cout << "Press Enter to continue.";
   cin.ignore(1000, '\n');
}
void test1() {
   int i;
   Box B[2] = { {3,3},{30,3} };
   cout << "Testing operator<< overload (pass 1): " << endl;
   cout << "These two outputs should match" << endl;
   cout << "Output 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1" << endl;
   for (i = 0; i < 2; i++) {
      cout << B[i] << endl;
      B[i].setCsv(true);
      cout << B[i] << endl;
   }
   cout << "Output 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2" << endl;
   cout
      << "* * *" << endl
      << "*   *" << endl
      << "* * *" << endl
      << "3,3" << endl
      << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl
      << "*                                                         *" << endl
      << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl
      << "30,3" << endl;
   cout << "**************************************************************" << endl;
}
void test2() {
   int i;
   ofstream bxout("boxes.csv");
   Box B[2] = { {3,3},{30,3} };
   for (i = 0; i < 2; i++) {
      B[i].setCsv(true);
      bxout << B[i] << endl;
   }
   bxout.close();
   ifstream bxin("boxes.csv");
   cout << "Testing operator<< overload (pass 2): " << endl;
   cout << "These two outputs should match" << endl;
   cout << "Output 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1" << endl;
   while (bxin) {
      cout << char(bxin.get());
   }
   cout << "\rOutput 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2" << endl;
   cout << "3,3\n30,3\n";
   cout << "**************************************************************" << endl;
}
void test3() {
   Box B;
   cout << "Testing operator>> overload (pass 1): " << endl;
   cout << "Enter the following: " << endl;
   cout << "4 <ENTER>" << endl;
   cout << "5 <ENTER>" << endl;
   cin >> B;
   cout << B << endl;
}
void test4() {
   int i;
   ifstream bxin("boxes.csv");
   Box B[2];
   for (i = 0; i < 2; i++) {
      B[i].setCsv(true);
      bxin >> B[i];
   }
   cout << "Testing operator>> overload (pass 2): " << endl;
   cout << "These two outputs should match" << endl;
   cout << "Output 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1" << endl;
   for (i = 0; i < 2; i++) {
      cout << B[i] << endl;
   }
   cout << "\rOutput 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2" << endl;
   cout << "3,3\n30,3\n";
   cout << "**************************************************************" << endl;
}
```
## MS3.1 Tester output
```text
Testing operator<< overload (pass 1):
These two outputs should match
Output 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
* * *
*   *
* * *
3,3
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                                                         *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
30,3
Output 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2
* * *
*   *
* * *
3,3
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                                                         *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
30,3
**************************************************************
Press Enter to continue.
Testing operator<< overload (pass 2):
These two outputs should match
Output 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
3,3
30,3
Output 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2
3,3
30,3
**************************************************************
Press Enter to continue.
Testing operator>> overload (pass 1):
Enter the following:
4 <ENTER>
5 <ENTER>
Width: 4
Height: 5
* * * *
*     *
*     *
*     *
* * * *
Press Enter to continue.Testing operator>> overload (pass 2):
These two outputs should match
Output 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
3,3
30,3
Output 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2
3,3
30,3
**************************************************************
```

## Milestone 3.2

To build a valet parking application we need to create a class that encapsulates a Vehicle to be parked in a parking spot and can be retrieved when it is needed to be returned to the customer.

### The Vehicle module:
Derive a class called Vehicle from the ReadWritable abstract base class in milestone 3.1.

A Vehicle class should be able to store a license plate with a maximum of 8 characters, a make and model with an unknown length of more than two characters and a parking spot number that is an integer value. 

### The Vehicle class implementation:
> When implementing the methods of the class, you are responsible to recognize if a member function can change the state of the Vehicle or not. (i.e. if it is a constant function or not or if the arguments of a function are constants or not)

### Attributes
#### License plate 
A license plate can be 1 to 8 characters. 

Example: “ABC123”

#### Make and model
A make and model Cstring value with unknown length. This value can not be a null address and can not be empty.

Example: “Bmw 320 M” 

#### Parking spot number 
A parking spot number can be a zero or positive integer number. A Vehicle with a zero (0) parking spot number is considered a vehicle that is not parked.  

### Constructors
a Vehicle can be created using a no-argument constructor that sets the Vehicle to a safe Invalid empty state. Also, a Vehicle can be created using a license plate and a make and model value. In the latter case, the values are used to set the properties of the Vehicle and the parking spot is set to zero. If either of the licence plate or make and model are pointing to null or are invalid values, the Vehicle is set into an invalid empty state. 

### Rule of three
Make Sure a Vehicle is copied and assigned to another vehicle safely and also make sure there is no memory leach when going out of scope or deleted.

### Methods 
#### setEmpty
sets the Vehicle to an invalid empty state
#### isEmpty 
This function returns true if the Vehicle is in an invalid empty state, or else, it returns false.
#### getLicensePlate 
This function returns a read-only address of the license plate of the Vehicle.
#### getMakeModel
This function returns a read-only address of the make and model of the Vehicle.
#### setMakeModel
This function resets the make and model of the Vehicle to a new value. If the new value is null or empty, the object is set to an invalid empty state.
Public Member function and operator overload implementations:
#### getParkingSpot
This function returns the parking spot number of the Vehicle.
#### setParkingSpot
Resets the parking spot number to a new value. If the value is invalid, it will set the vehicle to an Invalid empty state.
#### operator==
Compares the license plate of the Vehicle with a license plate value and returns true if the two license plates are identical or else it returns false. This comparison is NOT case sensitive (i.e. “123ABC” is the same as “123abc”).

If any value is invalid, this function returns false;
#### operator==
Compares two Vehicles and if they have the same license plate, it will return true, or else it returns false. 
This comparison is NOT case-sensitive.

If any value is invalid, this function returns false;

#### read
This function overrides the Read of the ReadWritable class. 

If the vehicle is set to Comma Separated mode it will read as follows:
1.	It will read an integer for the parking spot number into the parking spot number
2.	It will ignore one character for the delimiter (comma ‘,’)
3.	It will read up to 8 characters or up to a comma character for the license plate and store it in the license plate number in all UPPERCASE. Either way, it will skip the comma afterwards.
4.	It will read up to 60 characters or up to a comma character delimiter for make and model and dynamically stores it in the make and model of the Vehicle. Either way, it will skip the comma afterwards.

If the Vehicle is not set to Comma Separated mode it will read as follows:

It will prompt on the screen:<br />
`"Enter Licence Plate Number: "`<br />
Then it will read up to 8 characters from the console. If the user enters more than 8 Characters, it will print the following error message and tries again until a proper license plate number is entered.<br />
`"Invalid Licence Plate, try again: "`<br />
Then it will prompt:<br />
`"Enter Make and Model: "`<br />
Afterwards, it will read 2 to 60 characters from the console. If the user enters a value with an invalid length, it will print the following error message and tries again until a proper make and model are entered.<br />
`"Invalid Make and model, try again: "`<br />
Then in any mode (comma separated or not), the Read function will check if the istream object failed while reading. If this was true it will set the Vehicle object to an invalid empty state.


Also, license plates are always stored as all UPPERCASE characters and the parking spot number is set to zero (0);

In the end, the istream object is returned.

#### writeType (pure virtual)
**writeType** receives and returns a reference of ostream.

This pure virtual method in future generations of Vehicle classes will print the type of Vehicle.

#### write
If the Vehicle is in an invalid empty state, this function will write the following message using the ostream object and returns it.

`"Invalid Vehicle Object"`

Otherwise, it will call the **writeType** method and if the class is in comma-separated mode, it will print the values of the parking spot, license plate and make and model, separated by commas and ending by a comma without going to newline. (i.e `12,ABC123,Bmw 320 M,` )

If the class is not in comma-separated mode, it will print the following using the ostream object:
1. `"Parking Spot Number: "` 
2. Parking spot number or "N/A" if the parking spot is zero
3. NEWLINE
4. `"License Plate: "`
5. Vehicle’s license plate
6. NEWLINE
7. `"Make and Model: "`
8. Vehicle’s Make and model
9. NEWLINE

write returns the ostream object at the end.

### Other member functions:
Add other member functions to the Vehicle class if needed.


## MS3.2 Tester program
```C++
/* ------------------------------------------------------
Final Project Milestone 3.2
Module: ReadWritable
Filename: VehicleTester.cpp
Version 1.0
Author	Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------*/


#include <iostream>
#include "Vehicle.h"
using namespace std;
using namespace sdds;
class Truck : public Vehicle {
public:
   Truck() {};
   Truck(const char* lp, const char* mm) :Vehicle(lp, mm) {};
   ostream& writeType(ostream& ostr)const { return ostr; };
};
void TestValidations();
void TestOperatorEqualEqual( Truck A, Truck B);
void TestIO(Vehicle& V);
int main() {
   Truck V;
   Truck C("abcd", "C car");
   // you can comment each test to develop your Vehicle step by step: 
   TestIO(V);
   TestOperatorEqualEqual(C, V);
   TestValidations();
   return 0;
}
void TestIO(Vehicle& V) {
   ReadWritable& rw = V;
   cout << "Invalid Vehicle Printing:" << endl;
   cout << rw << endl;
   cout << "Reading vehicle from console: " << endl;
   cout << "Enter:" << endl << "abc<ENTER>" << endl << "abc<ENTER>" << endl;
   rw.setCsv(false);
   cin >> rw;
   cout << "Printing a Vehicle that is not parked:" << endl;
   cout << rw << endl;
   V.setParkingSpot(12);
   cout << "Printing a Vehicle that is parked in the spot number 12:" << endl;
   cout << rw << endl;
   cout << "Reading and Writing Comma Separated values: " << endl;
   cout << "Enter: " << endl;
   cout << "123,abcd,abcd,<ENTER>" << endl;
   rw.setCsv(true);
   cin >> rw;
   cin.ignore(1000, '\n');
   cout << rw << endl;
}

void TestValidations() {
   Vehicle* V;
   cout << "Construction validations:" << endl;
   V = new Truck(nullptr, "abc");
   cout << *V;
   delete V;
   V = new Truck("123456789", "abc");
   cout << *V;
   delete V;
   V = new Truck("", "abc");
   cout << *V;
   delete V;
   V = new Truck("ABC", nullptr);
   cout << *V;
   delete V;
   V = new Truck("ABC", "");
   cout << *V;
   delete V;
   V = new Truck("ABC", "A");
   cout << *V;
   cout << "Input validations: " << endl;
   cout << "Enter: " << endl << "123456789<ENTER>" << endl << "abc<ENTER>" << endl << "abc<ENTER>" << endl;
   cin >> *V;
   cout << *V << endl;
   cout << "Enter: " << endl << "abc<ENTER>" << endl << "a<ENTER>" << endl << "ab<ENTER>" << endl;
   cin >> *V;
   cout << *V << endl;
   cout << "Testing setParkingSpot validation: " << endl <<  "Valid setting: " <<endl;
   V->setParkingSpot(20);
   cout << *V << endl;
   cout << "invalid setting: " << endl;
   V->setParkingSpot(-1);
   cout << *V << endl;
   delete V;
}
void TestOperatorEqualEqual(Truck A, Truck B) {
   cout << "opeator== (cstring):" << endl;
   if (A == "Abcd") {
      cout << "operator== with cstring works" << endl;
   }
   else {
      cout << "Bad Opertor==, fix your code" << endl;
   }
   cout << "opeator== (Vehicle):" << endl;
   if (A == B) {
      cout << "operator== with Vehicle works" << endl;
   }
   else {
      cout << "Bad Opertor==, fix your code" << endl;
   }
}

```
## MS3.2 Tester program execution
```text
Invalid Vehicle Printing:
Invalid Vehicle Object

Reading vehicle from console:
Enter:
abc<ENTER>
abc<ENTER>
Enter License Plate Number: abc
Enter Make and Model: abc
Printing a Vehicle that is not parked:
Parking Spot Number: N/A
License Plate: ABC
Make and Model: abc

Printing a Vehicle that is parked in the spot number 12:
Parking Spot Number: 12
License Plate: ABC
Make and Model: abc

Reading and Writing Comma Separated values:
Enter:
123,abcd,abcd,<ENTER>
123,abcd,abcd,
123,ABCD,abcd,
opeator== (cstring):
operator== with cstring works
opeator== (Vehicle):
operator== with Vehicle works
Construction validations:
Invalid Vehicle Object
Invalid Vehicle Object
Invalid Vehicle Object
Invalid Vehicle Object
Invalid Vehicle Object
Invalid Vehicle Object
Input validations:
Enter:
123456789<ENTER>
abc<ENTER>
abc<ENTER>
Enter License Plate Number: 123456789
Invalid License Plate, try again: abc
Enter Make and Model: abc
Parking Spot Number: N/A
License Plate: ABC
Make and Model: abc

Enter:
abc<ENTER>
a<ENTER>
ab<ENTER>
Enter License Plate Number: abc
Enter Make and Model: a
Invalid Make and model, try again: ab
Parking Spot Number: N/A
License Plate: ABC
Make and Model: ab

Testing setParkingSpot validation:
Valid setting:
Parking Spot Number: 20
License Plate: ABC
Make and Model: ab

invalid setting:
Invalid Vehicle Object
```
### MS3 Tester program
The [`main.cpp`](ms3/main.cpp) tester program is the sum of the two tests (MS3.1 and MS3.2) in one file and the execution output therefore is the sum of the two outputs

## MS3 Submission 

> If you would like to successfully complete the project and be on time, **start early** and try to meet all the due dates of the milestones.

Upload your source code and the tester program to your `matrix` account. Compile and run your code using the `g++` compiler [as shown in the introduction](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 2??/prj/m3
```
and follow the instructions.

- *2??* is replaced with your subject code


### The submit program's options:
```bash
~prof_name.prof_lastname/submit DeliverableName [-submission options]<ENTER>
[-submission option] acceptable values:
  "-due":
       Shows due dates only
       This option cannot be used in combination with any other option.
  "-skip_spaces":
       Do the submission regardless of incorrect horizontal spacing.
       This option may attract penalty.
  "-skip_blank_lines":
       Do the submission regardless of incorrect vertical spacing.
       This option may attract penalty.
  "-feedback":
       Check the program execution without submission.
```



## [Back to milestones](#milestones)


# Milestone 4

To be continued

## [Back to milestones](#milestones)


# Milestone 5

To be continued

## [Back to milestones](#milestones)


