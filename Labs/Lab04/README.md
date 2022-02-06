# Lab 04 - NOT FINALIZED

- [Lab Procedure](#Lab-Procedure)
- [Part 1 - Regular Expressions](#Part-1---Regular-Expressions)
- [Part 2 - .profile and PATH](#Part-2---.profile-and-PATH)
- [Part 3 - Parsing Data](#Part-3---Parsing-Data)
- [Submission](#Submission)
- [Rubric](#Rubric)

## Lab Procedure

[Return to here and select "Start Lab"](https://awsacademy.instructure.com/courses/13249/modules/items/1136419)

Use `ssh` to connect to your AWS Ubuntu instance.

Go to the folder that contains your repository (likely named `ceg2350-yourgithubusername`).

Create a new directory, `Lab04`

This lab will have you creating input files, scripts, and output files. All of your work should be found here.

Some questions will need you to write anwers in `Lab04.md` the [LabTemplate.md is here](LabTemplate.md).

- [Raw version of LabTemplate.md](https://raw.githubusercontent.com/pattonsgirl/Spring2022-CEG2350/main/Labs/Lab04/LabTemplate.md)

For each part below, you will be asked to do an action or answer a question. The actions are going to be commands - you will write the command you used as "answers" to the action requested. You are allowed to use multiple commands to solve an action. Just write down all that were needed to complete. Check with the TAs if you need clarification.

If you did something "wrong" make a note of it in your lab. These are learning experiences - writing them down will help you ask good questions later.

## Part 1 - regex

- **Useful commands for this part: `apt`, `find`, `wc`, `|`, `grep`, `egrep`**

1. Use the package manager `apt` to install a package named `wamerican`. Write the command used.

2. You now have a `words` file on your system. Use the `find` command to find where it is located. Write the command used and the location of the file.

3. Using `wc`, find out how many words are in the `words` file.

- **For each below, write the `grep` or `egrep` command you used as well as the word count of matches.**

4. How many words in the `words` file start with a vowel (uppercase OR lowercase)?

5. How many words in the `words` file have the word `cat` inside of the word?

- concatenate, for example, should be a match

6. How many words in the `words` file have a non-alphanumeric character in the word?

- ' , e with a hat are examples of non-alphanumeric characters

7. How many words in the `words` file have at least one letter `m` in the word?

- **Resources**
- [RegEx Cheatsheet](http://web.mit.edu/hackl/www/lab/turkshop/slides/regex-cheatsheet.pdf)

## Part 2 - get a grep

`grep` is a handy command to find patterns in text. `egrep` is `grep`, but allows for extended regex patterns. If a regex search with `grep` is misbehaving, you may need to use `grep -e` or `egrep`, OR enable POSIX regex using the `-P` option

```
grep [OPTIONS] PATTERN [FILE...]
```

Create a file named `grepdata.txt` in your `Lab04` folder. Put the contents of [grepdata.txt](grepdata.txt) in the file. Use `grep` or `egrep` to complete the searches below. Only write the command that makes the required match. DO NOT paste the results.

1. Print all lines that contain a phone number with an extension (the letter x or X followed by four digits).
   - Your answer must use the \{ and \} repetition specifier.
2. Print all lines that begin with three digits followed by a blank.
   - Your answer must use the \{ and \} repetition specifier.
3. Print all lines that contain a date after the year 2000.
4. Print all lines that contain CA in either uppercase or lowercase.
5. Print all lines that contain an email address (they have an @ in them), preceded by the line number.

## Part 3 - sed

`sed` is mostly commonly used as a search and replace command. In `sedfile.html` you'll find a simple html file. But we want to change it into markdown. Your task is to do this only using `sed` commands. Your fixed file should be named `sedfile.md`.

1. Remove all html end tags - anything with </stuff>
2. Replace all <li> tags and the whitespace before the tag with the markdown format for a bullet point: `- `
   - Note that is a dash followed by a single space
3. Replace <h1> tags with markdown for header tags: `# `
   - Note that is a hashtag followed by a single space
4. Replace <h1> tags with markdown for header tags: `## `
   - Note that is TWO hashtags followed by a single space
5. Remove the <ul> tags & remove the <html> tag
6. Due to a typo, replace the word `Batches` with the word `Matches`

## Part 4 - awk

## Extra Credit

Use any of the tools above to complete the following challenges

1. In `grepdata.txt`, surround the first three digits of each phone number with parenthesis.
   - https://linuxize.com/post/how-to-use-sed-to-find-and-replace-string-in-files/

## Part 5 - Parsing Data

There are all sort of reasons to automate tasks. Some I do every semester including getting a list of all of your names and emails, then parsing it for only the emails so that I can make accounts for you on different systems (GitHub Classrooms and AWS Educate).

A sample data list you can use is in [registered-users.txt](registered-users.txt) - you just need to copy its contents to a file on your system.

- ** For starters, create this script in your `Lab04` folder.**
- Write a script named `parser` that performs the following objectives:
- Make sure it has permission to be executed. If you run the script with `source` the `exit` command will make you sad ;)

1. Prompts the user for a file with user and email data.

   - Verify the file exists.
   - If the file does not exist, tell the user they gave you bad input, and `exit` the program
   - Hint: `read`, `test`, `exit`

2. For the file:

   - Parse out only the email address that end in `wright.edu`
     - There are different approaches: "Remove the junk" OR "Find the good"
     - There is no explicitly right approach, just the one that works for how you think about the problem
   - Output the verified emails to `clean-emails.txt`
     - This output should only contains the emails, and nothing else.
   - You can use a for loop OR `egrep`, whatever floats your boat.

3. If the script is given the argument `-h`, print out a simple help guide stating:

   - what the script does
   - expected input
   - where output will be stored
   - ends program after printing the help guide
   - the help guide should not print unless the `-h` option is given
   - else the script should run its regular duties
   - **Note** - this is to make you think about the order of your script

4. Copy your script into your `bin` folder, and make sure it has appropriate permissions to run. Write the command(s) you used

- **Hints and Resources**
- Don't dive straight into the script and hope. Get little parts working. For example:
  - On the command line, parse the file with `grep` or `egrep` and see what command(s) are needed to get just the emails
  - Get a for loop working that prints out each line in the file (if you choose the loop route)
  - Get an if statement working that triggers in the script is run with `-h` as the argument
- [Loop through lines in a file](https://codefather.tech/blog/bash-loop-through-lines-file/)
- [Play with regex and your input](https://regex101.com/)

## Submission

1. Verify that your GitHub repo has a `Lab04` folder with at minimum:

   - `parser`
   - your input file
   - `clean-emails.txt`
   - `Lab04.md`

2. In the Pilot Dropbox, paste the URL to the `Lab04` folder in your GitHub repo
   - URL should look like: https://github.com/WSU-kduncan/ceg2350-YOURGITHUBUSERNAME/tree/main/Lab04

## Rubric

- Part 1 - 1 pt per question
- Part 2 - 1 pt per question
- Part 3:
  - if statement that checks for file existence, else exits - 1 pt
  - if statement that prints usage guide if argument is `-h` then exits - 1 pt
  - parses input file for just @wright.edu email addresses - 2 pts
  - outputs only @wright.edu email addresses to `clean-emails.txt` - 2 pts

## Credit

- grep exercises: http://evc-cit.info/cit052/grep1.html
