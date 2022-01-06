# Lab 01

The purpose of this lab is to familiarize yourself with the lab space we will be using  
for the remainder of the labs. You should have received an email regarding your AWS  
Educate account for this class. We will be using AWS to create virtual environments  
for you to use to complete the tasks given.

- [Part 1 - Provision Lab Environment in AWS](#Part-1---Provision-Lab-Environment-in-AWS)
- [Part 2 - Connecting to the AWS instance](#Part-2---Connecting-to-the-AWS-instance)
- [Part 3 - Git Fidgetting](#Part-3---Git-Fidgetting)
- [Part 4 - Try out markdown and play with `git` commands](#Part-4---Try-out-markdown-and-play-with-git-commands)
- [Submission](#Submission)

## Objectives

1. Get Started with AWS Educate
2. Start building your git(hub) toolbox
3. Use some linux commands in your AWS instance
4. Submit your answers to Pilot in a .txt file

**Important Note:** This AWS instance only allows inbound access from following ports:

- 22

## Pre-Reqs:

- A GitHub account
- A terminal on your system
  - [See Environment Setup](../../EnvironmentSetup.md)
- A text editor
  - I recommend [Visual Studio Code](https://code.visualstudio.com/) as a cross platform solution (plus dark mode looks cool)
  - You can also use any default text editor on your system (Notepad, Notepad++, or whatever Mac's have).

## Lab Procedure

Perform the following tasks. Document your answers in a plain text file named `Lab01-LastName.txt` where LastName is your last name. At the top of the file please enter your personal details as follows:

```
Name: Your name
Email: Your email

```

## Before you start: Register for AWS Educate

You should have an email from AWS Educate to guide you through account creation.  
Note: The email was sent to your wright.edu email account

_Registration form warnings_:

- Make sure you set a **graduation date** IN THE FUTURE
  - For Fall 2021, I recommend using 12/30/2030
- The last field on the right is a **Promotional Code** field. Your autofill may mistake it for a  
  zip code and unhelpfully fill it out for you. Make sure the Promotional Code field is _blank_ (empty)

Once you have filled in the registration information and verified your email address, you will get an account  
approval email. For reference, mine took 2-3 minutes to arrive.

## Part 1 - Provision Lab Environment in AWS

Assuming you have registered for AWS Educate and have access to this class, perform the following:

- [Sign in to AWS educate](https://www.awseducate.com/signin/SiteLogin)

  - Click the `My Classrooms` Button
  - Click the blue `Go to classroom` button for _Operating Systems Concepts and Usage_
  - Click the blue `AWS Console` button

  This will launch the AWS console  
  Note: If you were already logged in with your personal account, click the log out prompt and log back in with your university account

  Your username in the top right should look something like this  
  `vocstartsoft/user236529=lastname.number@wright.edu`.

Create an SSH key pair to get to your virtual machine.

- Click the Services menu, then select EC2 under Compute  
  [EC2 service from the AWS console](https://console.aws.amazon.com/ec2/v2/home?region=us-east-1#Home:)  
  In the center area you should see a list of all Resources you have available.  
  Right now they should all be 0.
- Click on [Key Pairs](https://console.aws.amazon.com/ec2/v2/home?region=us-east-1#KeyPairs:sort=keyName)
- Click on the `Create Key Pair` blue button.
  - Choose the name for your key. I used `ceg2350-aws-vm`  
    **MAKE SURE YOU SELECT SSH (pem) as the key type**
  - This creates a public/private key pair, stores the public key in AWS, and downloads the private key to your local machine.
  - **Do not lose the downloaded key.**
  - Back it up to a USB drive or your Office365 account. Once you go through the steps below, this key will be the only way to log in to your AWS instance. If the key is lost, you will need to delete the environment and start from scratch.

Create your AWS instance

- Once you have created your SSH key, [click here to provision your virtual environment](https://console.aws.amazon.com/cloudformation/home?region=us-east-1#/stacks/new?stackName=ceg2350&templateURL=https:%2F%2Fwsu-cecs-cf-templates.s3.us-east-2.amazonaws.com%2Fcourse-templates%2Fceg2350.yml)
  - LINK UPDATED 8/26/2021 - if you clicked the link before this message, you need to delete the old verion of your stack.  See Remaking your AWS educate environment
  - This link autofills many fields for creating our virtual machine.
  - On the first menu, click Next
  - On the second menu, under Parameters, type the name of the key pair you made in the  
    step above. If you don't remember, you can [open your key list here](https://console.aws.amazon.com/ec2/v2/home?region=us-east-1#KeyPairs:sort=keyName). Click Next
  - On the third menu, select Next
  - Scroll to the bottom and select Create Stack
  - You will be redirected to a status page that says CREATE_IN_PROGRESS

- Once you have created the AWS Cloud formation stack you can [return to the EC2 service](https://console.aws.amazon.com/ec2/v2/home?region=us-east-1#Home:).  
  Here you should see additional resources have been created (not everything says 0 anymore)
- Click on [Running Instances](https://console.aws.amazon.com/ec2/v2/home?region=us-east-1#Instances:sort=instanceState)
- Our machine should now be created (or almost ready).
- Your machine will be assigned an Elastic IP address. This IP address is what we will use to SSH into the
  virtual environment.

**WARNING**
While exploring and discovery is an important part of this course, any additional resources you create in AWS have an associated charge. If resources besides those strictly asked for by this course stay running, you risk running out of funds for this course. While fixable, this will hinder your ability to complete labs on time. Please let the TA's know if you need assistance cleaning up you environments.

### Part 1 Lab Report Questions: (2 pts)

1. What is the IP address for your environment? (2 pts)

## Part 2 - Connecting to the AWS instance

**You are now ready to make an SSH connection to your AWS server.**

1. Open Ubuntu or another terminal.
2. Copy the AWS SSH key that AWS made you download into your user's home directory
  - Helpful commands: `cd, cp, ls, man`
  - The manual method (especially for those using WSL2): 
  - In your user's home directory, create a file named `ceg2350-aws-vm.pem`
  - Open the file in a text editor (`vim` or `nano`)
  - Copy and paste the contents of the key that was downloaded from AWS Educate into the file.
3. Change the permissions on the key file in your directory
  - Because private keys need to be protected, the key needs to be changed to readable by your user by using `chmod`
  - `chmod 600 /path/to/private/key` - replace _/path/to/private/key_ with your information
  - Resource on how to use [chmod](https://www.howtogeek.com/437958/how-to-use-the-chmod-command-on-linux/)
4. SSH into your AWS server with the following command  
   `ssh -i /path/to/private/key ubuntu@ElasticIP`  
   Note: replace _/path/to/private/key_ and _ElasticIP_ with your information
  - If your connection was refused, you may have forgotten to put the username `ubuntu` in front of your Elastic IP address
  - If prompted, type 'y' or 'yes' to continue connecting
5. You are now signed in to your AWS Educate system as the user `ubuntu`

### Part 2 Lab Report Questions: (4 pts)

1. How do you exit `vim`? (1 pt)
2. Write the command you used to `ssh` in to your AWS instance. (2 pts)  

- `ssh` into your AWS instance for the question(s) below. Provide the command(s) used to find your answers.  
3. Read `/etc/os-release`. What is the PRETTY_NAME of the Operating System in AWS? (1 pt)  
   **Useful Commands: `cat, cd`**

## Part 3 - Git Fidgetting

1. Create or sign in to your [github](https://github.com/) account.
2. Follow the [instructions here](../../GitHubClassrooms.md) to set up your repository and perform your first clone! 
  - If you previous followed these instructions for your personal machine, follow the SSH key setup part and clone for your system on AWS

### Part 3 Lab Report Questions: (3 pts)

1. Write the URL to your GitHub repository setup in GitHub classrooms. (1 pt)
2. Write the command you used to clone your repository. (2 pts)

## Part 4 - Try out markdown and play with `git` commands

So far, you have been doing what this lab told you.  You created a .txt file.  You have likely found out that any fancy formatting doesn't exist.  It's just text.  Therefore, you are going to create your first file using `markdown`.  
If you look around in the folder you cloned, you'll see a folder named `sample`.  In `sample` is a sample file with some commonly used markdown.  You can see how this markdown looks by going to your repository in the browser, clicking into the sample folder, and clicking on `markdown-guide.md`
- [What is markdown?](https://www.markdownguide.org/getting-started/)

1. On your Ubuntu system we made on AWS (previous steps), go into the folder you cloned  
   **Useful Commands: `pwd, ls, cd`**
2. Create and open a file named `Lab01.md`  
   **Useful Commands: `vim`**
3. Check out the [Lab Template](LabTemplate.md)
  - View the [raw version of the Lab Template](https://raw.githubusercontent.com/pattonsgirl/Fall2021-CEG2350/main/Labs/Lab01/LabTemplate.md) 
4. Copy the format of the lab template and fill it in with your lab answers.
  - [Basic `vim` usage](https://www.howtoforge.com/vim-basics)
5. You have now made a new file, added some text to it, and (hopefully) made it look fancy... but how can we test this?
6. Use `git` commands to `add`, `commit` and `push` the file you made to GitHub.
  - If successful, when you go to the repository in your browser, you'll see `Lab01.md` as something you can click to view.
7. Now that you can see it, go back to your file and make tweaks if needed to fix the markdown.
  - Once you are done making changes, use `git` commands to `commit` and `push` the changes to GitHub - hitting refresh will show the updated version.

**Resources**
- [git + GitHub guide](https://guides.github.com/introduction/git-handbook/)
  - This is more than you need, but well done for the basic usage of `add`, `commit`, `push`

### Part 4 Lab Report Questions: (1 pt)

There are none, proof is in the proverbial pudding.  Head to Submission  
Successful completion of this portion is worth 1 pt

## Submission

- If `Lab01.md` is in your repository and verified viewable on GitHub:
  1. In the Pilot Dropbox, paste the URL to the `Lab01.md` file in your GitHub repo
    - URL should look like: https://github.com/WSU-kduncan/ceg2350-YOURGITHUBNAME/Lab01.md

- If not:
  1. Reach out to the TAs and / or I.  Getting this process down is required for future lab submissions.
  2. Add to your Lab01-LastName.txt what steps you had trouble with
  3. Upload your file named Lab01-LastName.txt to the Pilot Dropbox for partial credit

### Acknowledgement

Credit to Matt Kijowski's GitHub Repo - [Lab 1 for Cyber Security Analysis](https://github.com/mkijowski/cyber-security-analysis-applied/blob/master/labs/lab1.md)
