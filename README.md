# Instructions
This assignment was locked Oct 16 at 3:30pm.
<br />This assignment should be done in teams of 2.  Remember to name both partners in the comment section of the submission as well as in comment block of the main.
<br />This should be done in Visual Studio or properly changed into a Visual Studio format before submitting.
<br />Upload the entire solution folder as a zip file.
<br />Both members should upload the exact same file - I will only grade one person's submission at random and both people will get the same score.
<br />If the team members are not identified, then both people will get a ZERO.
<br />If one member uploads late, then that submission will count for the team grade.
<br />Include one or more screenshots of your running program in your zip file as well.
<br />I will test your EXE first - if it doesn't run on my or CIS lab machines, it will be a 25% deduction without exception, so test your upload on a machine different from where it was created before uploading.
 

Programming problem: Simulate your wallet and its contents when on a foreign trip.

A. Create a currency class with four attributes - currency name, whole parts and fractional parts and fractional's name such that 100 fractional parts equals 1 whole part.
<br />B. Create 5 derived classes for the following currencies - Dollar, Euro, Yen, Rupee and Yuan. I know this program can be done without inheritance but it is a requirement for this lab. You will be adding and subtracting currency values using the form:
<br />Dollar, 1, 25, cent
<br />Euro, 3, 33, cent
<br />Yen, 100, 54, sen
<br />Rupee, 7, 11, paise
<br />Yuan, 50, 86, fen
<br />C. Define overloaded operators to add or subtract different currency objects - care should be taken that you can only perform these operation on objects of the same currency. Also, take care that fractional parts roll into whole parts.
<br />D. Define an overloaded input stream operator to accept values of any currency as well as an overloaded output stream operator to write out the value of the currency..
<br />E. When initializing currency objects, your code should demonstrate polymorphic construction.  Your constructors should also use initialization lists.
<br />F. Now, define a Wallet class that will contain the 5 individual currency types above and will implement the following - number of individual currency types, check if a currency type exists in the wallet, add money by currency, remove money by currency, remove all currencies, check if wallet is empty. What this means is that your wallet can only contain one object of each currency type. To add or remove money into/from wallet, check if currency exists in the wallet.  If so, add or remove the amount specified.
<br />G. Your main should allow the user to add a maximum of 5 different currency types to the wallet in the form of the base currency array - this will help you demonstrate the polymorphic construction.  Demonstrate the overloaded subscript operator for the Wallet class.  User should be able to add or remove as many currency values for any of the five currency types.  The user should also be able to output the total value by name of the currencies in the wallet.  Finally they should be able to empty the wallet and print relevant information about the operation.  User Interactivity is extremely important - give due consideration to it.

 

Things to remember:

Make any relevant assumptions that you may need but state them clearly in your name/comment block at the top. 
<br />Remember to document your methods adequately as well as any other relevant comments.  
<br />This program will need individual class declaration and implementation files for the currency and wallet classes and a file for your main, though you may combine various currencies into the same set of files.  Simply put - your project will consist of a minimum of 2 .h and 3 .cpp files.
<br />Do not write your methods as inline in your class declaration if they will be more than 2 statements - define them in their own cpp files.
<br />Name your solution and zip file as '22c_lab1_<initials 1>_<initials 2>, i.e. if Joe X Blow and Jane Y Doe are partners, then the name will be '22c_lab1_jxb_jyd' or '22c_lab1_yjd_jxb'.
 

Grading:

5 pts - EXE works from command line on class/lab machines.
<br />3 pts - complete and working MSVC17 solution with a minimum of 5 code files
<br />2 pts - overloaded addition, subtraction, input and output operators for Currency
<br />1 pts - polymorphic construction of Currency objects in the Wallet
<br />1 pts - overloaded subscript operator in Wallet
<br />3 pts - clear and intuitive user interactivity
<br />5 pts - inheritance, other code requirements, code styling, documentation and sundries
 

This assignment is due before class one week from today with possibility of late submission for one more week.

# Outcome
Well structured code
<br />-0.5 forgot to make currency destructors virtual for polymorphism
<br />-1 did not follow naming conventions or naming partner on Canvas