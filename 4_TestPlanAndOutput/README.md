# Test Plan and Test Ouput

| **Test ID** | **User ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**PASS/FAIL**  |    
|-------------|-----|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  T_1|Rajasekhar| Provide correct details for Login|Logged in| YOU HAVE LOGGED IN SUCCESSFULLY!! | YOU HAVE LOGGED IN SUCCESSFULLY!! | PASS |
|  T_2|Rajasekhar| Wrong credentials | Wrong Input | Try logging in again! | Try logging in again! | PASS |
|  T_3|Rajasekhar| Add details after LOGIN |  Add details of Employees | Add next details | Add next details | PASS |
|  T_4|Rajasekhar| Register | LOGIN CREDENTIALS , REGISTER new_user | Registered succesfully | Registered succesfully| PASS |
|  T_5|User/Employee| Display Salary details of All employees | '3' | Details in Window | Details in Windows | PASS |

# Unity test
| **Test ID** | **Unit test ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**PASS/FAIL**  |    
|-------------|-----|--------------------------------------------------------------|------------|-------------|----------------|------------------|
| T_6 |UT_1| Checking basic salary function |2, 2000|133.33|133.33|pass|
| T_7 |UT_2| Checking OT calculation |72, 7000|4200|4200|pass|
| T_8 |UT_3| Checking Pf Calculation |6000|720|720|pass|
| T_9 |UT_4| Checking Company name |ABC-AUTOMOBILES|1|1|pass|
| T_10 |UT-5| Checking User Name |Rajasekhar|1|1|pass|
