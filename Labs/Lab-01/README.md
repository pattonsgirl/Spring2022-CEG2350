# Lab 01

- [Lab Procedure](#Lab-Procedure)
- [Part 1 - Play with directories and naming](#Part-1---Play-with-directories-and-naming)
- [Part 2 - Create and edit a file](#Part-2---Create-and-edit-a-file)
- [Part 3 - Play with hidden files](#Part-3---Play-with-hidden-files)
- [Part 4 - Regular `bob`](#Part-4---Regular-bob)
- [Part 5 - Get a `crew`](#Part-5---Get-a-crew)
- [Part 6 - `sudo` make me a sandwich](#Part-6---sudo-make-me-a-sandwich)
- [Part 7 - `git` & GitHub](#Part-7---git-and-GitHub)
- [Extra Credit - Test your skills](#Extra-Credit---Test-your-skills)
- [Submission](#Submission)
- [Rubric](#Rubric)

## Lab Pre-Reqs

This lab assumes

1. That you have a working Linux / Unix based terminal

   - Windows users: WSL2
   - Mac users: Terminal
   - Linux / Unix users: Terminal

2. You have created a GitHub account and clicked the link in Pilot to generate your GitHub  
   repository for this course

   - If you forgot to bookmark it, the URL is similar to:
   - `https://github.com/WSU-kduncan/ceg2350-YOURGITHUBUSERNAME`

## Lab Procedure

For each lab in this course, you will be provided with a lab template to fill in your lab answers.

Document your answers in a plain text file named `Lab02-LastName.txt` where LastName is your last name. You can also skip down to Part 7 and start with the [LabTemplate.md](LabTemplate.md).

For each part below, you will be asked to do an action or answer a question. The actions are going to be commands - you will write the command you used as "answers" to the action requested. You are allowed to use multiple commands to solve an action. Just write down all that were needed to complete. Check with the TAs if you need clarification.

```
Example:
Prompt: Create a file named bubbles.txt
Answer: `touch bubbles.txt`
```

If you did something "wrong" make a note of it in your lab. These are learning experiences - writing them down will help you ask good questions later.

It is expected that all parts are done on your AWS instance (the thing you `ssh` into).

## Part 1 - Play with directories and naming

- **Useful commands for this part: `man, mkdir, cd, ls, pwd, mv`**

1. Create a directory called `DirA`
2. Create a directory called `Dir B`
   - You must end up with a folder named `Dir B`
3. How do you go into `Dir B`?
4. Which of these uses a better naming convention, and why?
5. Rename `Dir B` to `DirB`

## Part 2 - Create and edit a file

- **Useful commands for this part: `touch, vim`**

1. In `DirA`, create a file called `test.txt`
2. Put at least three lines of text in `test.txt` using `vim`

## Part 3 - Play with hidden files

- **Useful commands for this part: `cp, mv, ls`**

1. Make a copy of `test.txt` inside `DirA` named `.hiddentext.txt`
2. Write the command and flags needed to see the file in `DirA`

## Part 4 - Regular `bob`

- **Useful commands for this part: `adduser, sudo, su, chown, pwd, cd, whoami, exit`**

1. Create a new user named `bob`
2. What is the path to `bob`'s `home` directory?
3. Can the `ubuntu` user add files to `bob`'s home directory? Why or why not?
4. Switch to the user `bob`
5. Get to `bob`'s `home` directory
6. Can `bob` add files to `bob`'s home directory? Why or why not?
7. Switch back to the `ubuntu` user
8. Return to the `ubuntu` user's `home` directory

## Part 5 - Get a `crew`

- **Useful commands for this part: `addgroup, usermod, chown, chgrp`**

1. Create a new group named `crew`
2. Add `ubuntu` and `bob` to the `crew` group
3. Change `DirA` in the `ubuntu` user's home directory so that `crew` is the group for the whole folder
   - Yes, including contents in `DirA`
4. Switch user to `bob`
5. As `bob` create a file in `DirA`.
6. Why was this successful?

## Part 6 - [`sudo` make me a sandwich](https://xkcd.com/149/)

- **Useful commands for this part: `sudo`**

1. In the `ubuntu` user's `home` directory, make a file with `sudo` named `sudowho.txt`
2. What are the permissions of this file?
3. Without modifying the permissions of the file, edit the file and add some text.

## Part 7 - `git` and GitHub

You do not need to write anything in your Lab for this part, just focus on getting answers up to GitHub.

1. On your Ubuntu system we made on AWS (Lab01), go into the folder you cloned  
   **Useful Commands: `pwd, ls, cd`**
2. Create and open a file named `Lab02.md`  
   **Useful Commands: `vim`**
3. Check out the [Lab Template](LabTemplate.md)

- View the [raw version of the Lab Template](https://raw.githubusercontent.com/pattonsgirl/Fall2021-CEG2350/main/Labs/Lab02/LabTemplate.md)

4. Copy the format of the lab template and fill it in with your lab answers.

- [Basic `vim` usage](https://www.howtoforge.com/vim-basics)

5. You have now made a new file, added some text to it, and (hopefully) made it look fancy... but how can we test this?
6. Use `git` commands to `add`, `commit` and `push` the file you made to GitHub.

- If successful, when you go to the repository in your browser, you'll see `Lab02.md` as something you can click to view.

7. Now that you can see it, go back to your file and make tweaks if needed to fix the markdown.

- Once you are done making changes, use `git` commands to `commit` and `push` the changes to GitHub - hitting refresh will show the updated version.

## Extra Credit - Test your skills

- **Useful commands for this part: All of the above!**

1. Create a file in `DirB` with the following permission set:
   - `-rw------- sally crew [size] [datetime] mydiary.txt`
   - where `[size]` and `[datetime]` are going to be unique for you
   - write all steps needed to make this happen
2. `ubuntu` would like to edit `sally`'s `mydiary.txt` file, just to mess with her. How can `ubuntu` do this without changing the permissions?
3. `bob` wants in on the joke to edit `sally`'s `mydiary.txt` file, just to mess with her. How can `bob` do this without changing the permissions?

## Submission

- In the Pilot Dropbox, paste the URL to the `Lab01.md` file in your GitHub repo
  - URL should look like: https://github.com/WSU-kduncan/ceg2350-YOURGITHUBUSERNAME/blob/main/Lab01.md

## Rubric

- Each question is worth 1 point.
- This lab is worth a total of 26 points
- The extra credit is also worth 1 point per question
- This makes the extra credit worth ~11.54%
