# Lab 02 - NOT FINALIZED

- [Lab Procedure](#Lab-Procedure)
- [Part 1 - git cloning](#Part-1---git-cloning)
- [Part 2 - IO Redirection](#Part-2---IO-Redirection)
- [Part 3 - Intro to Scripts](#Part-3---Intro-to-Scripts)
- [Part 4 - Intro to Regular Expressions](#Part-4---Intro-to-Regular-Expressions)
- [Part 5 - Docs and Repos](#Part-5---Docs-and-Repos)
- [Extra Credit - Colorize Me, Captain](#Extra-Credit---Colorize-Me,-Captain)
- [Submission](#Submission)
- [Rubric](#Rubric)

## Lab Procedure

For each part below, you will be asked to do an action or answer a question. The actions are going to be commands - you will write the command you used as "answers" to the action requested. You are allowed to use multiple commands to solve an action. Just write down all that were needed to complete. Check with the TAs if you need clarification.

If you did something "wrong" make a note of it in your lab. These are learning experiences - writing them down will help you ask good questions later.

## Part 1 - git cloning

- **Useful commands for this part: `ssh-keygen`, `cat`, `git clone`, `git add`, `git commit`, `git push`**

1. Create an SSH key pair on your local system.
2. Add the public key to GitHub
3. Clone your repository (a.k.a. repo) in your terminal
4. In your repo folder, create a folder named `Lab02`
5. In the `Lab02` folder, create a file named `Lab02.md`
6. Paste the contents of the [LabTemplate.md](LabTemplate.md) into this file
7. `add` `Lab02.md` for tracking, `commit` changes as you go, and `push` to synchronize with GitHub

- **Resources:**
- [GitHub Classrooms - How to Use](GitHubClassrooms.md)

## Part 2 - IO Redirection

This and the following parts are meant to be done in your `Lab02` folder in your repo.

- **Useful commands for this part: `man, vim, sort, <, >, >>`**

1. Create a file called `input.txt` with the following contents:

```
9.1
43.7
2.2
62.1
2.1
9.3
43.5
4.6
44.6
4.7
42.7
47.4
46.6
4.5
55.6
4
9.2
66.6
2
2.3
```

2. Direct the file `input.txt` into the `sort` command. (1 pt)
3. Direct the file `input.txt` into the sort command and direct the output to `output.txt`. (1 pt)

- **Resources:**
- [An Intro to Linux IO Redirection](https://www.digitalocean.com/community/tutorials/an-introduction-to-linux-i-o-redirection)
- [IO Redirection](https://tldp.org/LDP/abs/html/io-redirection.html)
- [Unix `sort` command](https://www.computerhope.com/unix/usort.htm)

## Part 3 - Intro to Scripts

1. Create a bash script called `sorting-party`. The script should have the following features:

   - Reads in a filename as an argument.
     - Runs with `sorting-party filename`
   - Sorts the contents of the file given in the argument using the `sort` command.
   - Outputs the sorted data to a file called `sorted.txt`

- Hint: To run your script you may need / want to play with the file permissions.

- **Resources:**
- [Command Line Arguments in Shell Script](https://tecadmin.net/tutorial/bash-scripting/bash-command-arguments/)
- [Use Command Line Arguents in Bash Script](https://www.baeldung.com/linux/use-command-line-arguments-in-bash-script)
- [Positional Parameters](http://linuxcommand.org/lc3_wss0120.php)

## Part 4 - Intro to Regular Expressions

1. Add an `if` statement to your script that checks if the file in the argument ends in `.txt`
2. If the file does **not** end in `.txt` your script should exit with an error message: `File extension not allowed`

- Hint: maybe make some other files with other file extension to test your else statement

- **Resources:**
- [How to Use Regex in Bash](https://www.poftut.com/how-to-use-regular-expression-regex-in-bash-linux/)
- [Regex 101](https://regex101.com/)

## Part 5 - Docs and Repos

1. Fill in the "Script Usage Guide" section with at least the specified elements
   - You are welcome to replace this with any additonal markdown you would like to make it look good
2. Verify that your GitHub repo has a `Lab02` folder with:
   - `input.txt`
   - `output.txt`
   - `sorting-party`
   - `Lab03.md`

## Extra Credit - Colorize Me, Captain

Colorize the error condition from your script (`File format not allowed`). Maybe go for traditional red? How does purple make you feel? Rainbow and plaid are also welcome to this party.

Make sure you `commit` and `push` your script changes for grading.

## Submission

- In the Pilot Dropbox, paste the URL to the `Lab02` folder in your GitHub repo
  - URL should look like: https://github.com/WSU-kduncan/ceg2350-YOURGITHUBUSERNAME/tree/main/Lab02

## Rubric

- Each part of this lab is worth 2 pts
- The extra credit is worth 0.5 pts
  - translates to 5%
