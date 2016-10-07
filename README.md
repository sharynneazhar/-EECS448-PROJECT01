# Calendar
A basic academic calendar written in C++ for KU EECS 448

### Date vs. Day
In this project, we use the term __date__ to describe a specific number like the __10th__, whereas the term __day__ refers to the entire date like __October 10th, 2016__.

## Program Requirements
The user must be able do the following:
- All requirements from project 1
- Events with time frames
  - A detail/event can be given a time frame (e.g. 11am-11:50am)
  - Multiple events that overlap in timeframe should be easy for the user to notice
  - In 1-day view, events should be ordered by the time
- Multiday events
  - Events should be able to span multiple days (e.g. Fall break would be a mulitday event)
- Recurring events
  - When creating an event, the following options should be presented:
    - Repeat weekly, biweekly, or monthly
    - Repeat based on day of the week (e.g repeats weekly every Monday, Wednesday, and Friday) OR based on date
    (e.g. Pay rent first of every month)

## Running the Project
- Open the terminal and navigate into the project folder `$ cd path/to/eecs448-project02`
- Build the project by typing `$ make` in the terminal
- Run the project with the following command `$ ./calendar`

To clean the project, run the following command `$ make clean`

## Running Doxygen
- Make sure you have [Doxygen][9] installed in your environment:  
  (Tip: If you have Homebrew installed, just run `$ brew install doxygen`)
- To generate the documentation you can now enter:  
  `$ doxygen Doxyfile`

The generated HTML documentation can be viewed by pointing the browser to `path/to/documentation/html/index.html`

## Issues
If you see a bug in the app, feel free to create a new issue [here][10].


## Contributors
#### Burger Lovers
This project was originally created by [athoma35][1], [greatyehanli][2], [katiehrenchir][3], and [cridermac][4]

#### Team ESAP
This project is currently maintained by [sharynneazhar][5], [erincoots][6], [ashlimosiman][7], and [parthvip28][8]


[1]: https://github.com/athoma35
[2]: https://github.com/greatyehanli
[3]: https://github.com/katiehrenchir
[4]: https://github.com/cridermac
[5]: https://github.com/sharynneazhar
[6]: https://github.com/erincoots
[7]: https://github.com/ashlimosiman
[8]: https://github.com/parthvip28
[9]: http://www.stack.nl/~dimitri/doxygen/download.html
[10]: https://github.com/sharynneazhar/eecs448-project02/issues
