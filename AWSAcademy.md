# Over Simplified Instructions

1. Open email to accept invite to course
2. By default, taken to AWS Academy Learner Lab - Foundation Services [13249]
   - Important notes:
     - Sessions last 4 hours. Session time can be refreshed. Instances spin down after 4 hours
     - Budget cannot exceed $100 - account will vaporize - all resources created by account will be deleted
3. Click "Modules"
4. Click "Learner Lab - Foundational Services"
5. Click the "Start Lab" Play button on the middle right
6. Wait. 2 - 3 minutes. You will see a console appear that you can interact with.
   - This terminal is configured with AWS CLI access - you can query resources created on your account with it, but in itself is not what we are aiming for. Carry on.
7. Click AWS Details (with info icon next to it). Click download PEM from the SSH key options
   - Open key in text editor, copy its contents to a file in your home directory
8. Click "AWS" which should have a green dot next to it located on the left
   - This will take you to your AWS Console for your account. Now the fun begins.
9. In a new tab, enter the following URL in the browser (or click link to open): https://console.aws.amazon.com/cloudformation/home?region=us-east-1#/stacks/new?stackName=ceg2350&templateURL=https:%2F%2Fwsu-cecs-cf-templates.s3.us-east-2.amazonaws.com%2Fcourse-templates%2Fceg2350.yml
   - Click Next
   - Under Key Name, select `vockey`
   - Click Next
   - Scroll down, click Next
   - Scroll down, click Create Stack
10. Once you have created the AWS Cloud formation stack you can [return to the EC2 service](https://console.aws.amazon.com/ec2/v2/home?region=us-east-1#Home:).  
    Here you should see additional resources have been created (not everything says 0 anymore)
11. Click on [Running Instances](https://console.aws.amazon.com/ec2/v2/home?region=us-east-1#Instances:sort=instanceState)
12. Our machine should now be created (or almost ready).
13. Your machine will be assigned an Elastic IP address. This IP address is what we will use to SSH into the
    virtual environment.
14. Use SSH to log in: `ssh -i vockey.pem ubuntu@ElasticIP`

## TODOS

- Instructions to turn instance back on after 4 hours
- Figure out classroom divisions (students taking more than one AWS course at a time)
- People adding - name requirements?
