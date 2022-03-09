## Quiz 3 Review

1. I have a newly bought 4 TB SSD. Which partition table type should I create on it?

   - MBR and GPT were the only partition table types listed.
   - GPT supports disk size of 4TB
   - See Lecture 2/23 for another review comparing MBR to GPT partition tables

2. Circuit board that handles communication lines (busses) between components:

   - Motherboard has communication busses to enable communication lines between components

3. In between the UEFI and POST and the OS starting lies the \_\_\_\_. If UEFI detects a bootable partition on the disk, it will load this stage of the boot process, during which other OSes can be selected or option such as recovery mode or memory checking.

   - bootloader
   - GPT is not a stage of the boot process, it is a partition table type on the disk to be able to locate where partitions are located (where to start reading on different parts of the disk)
   - the kernel is loaded into RAM by the bootloader
   - NTFS is a filesystem type
   - see Lecture 2/23 for another review of the boot process

4. The alpha company has changed their name to zeta. Given the list of emails below, what sed command will accurately replace the old name with the new to fix the company email list stored in emails.txt?

Note: this has the spelling error of jim@aplha.com corrected

```
jim@alpha.com
meg@alpha.com
kay@alpha.com
matt@alpha.com
ben@alpha.com
```

- `sed -E 's/.*/zeta/g' emails.txt`
  - replaces all lines with `zeta`
- `sed -E 's/alpha/zeta/g' emails.txt`
  - replaces only `alpha` with `zeta` for each line
- `sed -E 's/zeta/alpha/g' emails.txt`
  - would replace the word `zeta` with `alpha` for each line
  - wrong logic order
- `sed -E 's/@\w+\./zeta/g' emails.txt`
  - removes the @ and . from each address, resulting line sample is: `jimzetacom`

5. I created a new file, used `git add file` to track it, used `git commit` to commit my changes in my repo, but on git push I get the following output:

```
To github.com:pattonsgirl/Spring2022-CEG2350.git
 ! [rejected]        main -> main (fetch first)
error: failed to push some refs to 'git@github.com:pattonsgirl/Spring2022-CEG2350.git'
hint: Updates were rejected because the remote contains work that you do
hint: not have locally. This is usually caused by another repository pushing
hint: to the same ref. You may want to first integrate the remote changes
hint: (e.g., 'git pull ...') before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
```

What command do I need to run next?

- This error shows when GitHub has content that you do not have locally (in your cloned copy of the repo)
- `git pull` based on reading output of message from running `git push`
- `git status` was also accepted as an answer
- `git push` again would result in the same output because I have not fixed the problem
- `git add .` would add all untracked files in the current directory. This does not fix the problem
- `git commit -a` would add and commit all tracked files. This does not fix the problem

6. When using getopts, the OPTARG variable holds the index number of the option being read.
   - `OPTARG` hold the argument value `getopts` is currently evaluating
   - `OPTIND` holds the index number of the option being read
   - see Lecture 2/21 for a review of `getopts` and exploring these `getopts` variables
7. When sorting a numeric list with the sort command, what option sorts the list numerically?
   - `-n` sorts the list numerically. Check out these results from Lab 03.
   - `man` command on `sort` to see other sort options

```
$ sort list.txt
2
2.1
2.2
2.3
4
4.5
4.6
4.7
42.7
43.5
43.7
44.6
46.6
47.4
55.6
62.1
66.6
9.1
9.2
9.3
$ sort -n list.txt
2
2.1
2.2
2.3
4
4.5
4.6
4.7
9.1
9.2
9.3
42.7
43.5
43.7
44.6
46.6
47.4
55.6
62.1
66.6
```
