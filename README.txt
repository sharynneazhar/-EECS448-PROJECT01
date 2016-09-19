September 9
ANDREW:
Here's the general idea for the project I've had so far:
  The user is welcomed to the program, chooses a date, then chooses to view the
date in month, week, or single day view, or add/remove a note from the chosen
date.
  To do this I want to create a month class that populates day class objects.
The day class would hold a integer value for the date, a character value for the
day of the week, a bool for if there is a note on this date or not, and functions
that return these values outside of the object. The month object would have a
string name variable, an integer for the number of days in that month, and a day
object for each day. (We may also need a variable to not what day of the week the
month starts on, I was thinking an int from 0-6 with Sunday being 0 through
Saturday being 6)
  Month and week views would be headed with a listing of days of the week, like
this:
Su  M T W R F Sa
The cout would essentially be
cout<<"Su\tM\tT\tW\tR\tF\tSa"<<endl;
I see month view being something like:
Su  M T W R F Sa
      1 2 3 4 5

6   7 8 9 10  11  12
    X     X       X
13  14  15  16  17  18  19
        X       X
20      21  22  23  24  25  26
etc.
The "X" under a date signifies that there is a note on that date.
  The other big part we need to work on is the permanence of date notes. That
can probably be done with notes being written to a .txt file with the rest of
the program files. We'll need to set up in the "add a note" and "delete a note"
functions file i/o (#include <fstream>) for writing to the file and reading off
that file in the initial calendar builder so it shows up whenever the program is
launched.
  I know it seems like a lot of work (at least it does to me), but there's four
of us, github, and a little over a week of time.

September 14
ANDREW:
  I've set up documentation for the project. Take a look at Day.h for the general
format of commenting on files for the system (the same commenting system used in
168/268). If you ever need to check the documentation, run "doxygen Doxyfile" in
the console while you're in the folder with this repository. Once that's done
(or you just want to check the current documentation) look in the "html" folder
for "index.html" and open that in your browser of choice.
