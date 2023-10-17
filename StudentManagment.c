#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Student
{
    char studentName[50];
    char studentId[15];
    char studentDept[10];
    char studentAddress[100];
    char studentContactNum[15];
    float studentCGPA;
    int rollno;
} Student;
Student recentlyAddedStudent;

typedef struct TreeNode
{
    Student data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
TreeNode *createNode(Student data);
void insertNode(TreeNode **node, Student data);
int displayCount(TreeNode *node);
void displayInOrderArray(TreeNode *node, Student students[], int *index);
void sortStudentsByCGPA(Student students[], int count);
void displayInOrder(TreeNode *node);
void displaySortedByCGPA(TreeNode *node);
TreeNode *searchNodeByRollNo(TreeNode *node, int rollno);
TreeNode *searchNode(TreeNode *node, int rollno);
void updateNode(TreeNode** node, Student newData);
void createAccount();
void displayInOrderWithRollNo(TreeNode *node);
void displayInfo();
int isRollNoUnique(TreeNode *node, int rollno);
void updateInfo();
void deleteAccount(TreeNode **node, int rollno);
void searchStudent(TreeNode *node, int rollno);
void displayRecentlyAddedStudent();
int countStudents(TreeNode *node);
TreeNode *root = NULL;

TreeNode *createNode(Student data)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insertNode(TreeNode **node, Student data)
{
    if (*node == NULL)
    {
        *node = createNode(data);
    }
    else
    {
        if (data.rollno < (*node)->data.rollno)
        {
            insertNode(&((*node)->left), data);
        }
        else
        {
            insertNode(&((*node)->right), data);
        }
    }
}

// Add this function to count nodes


// Add this function to store student data in an array
void displayInOrderArray(TreeNode *node, Student students[], int *index)
{
    if (node != NULL)
    {
        displayInOrderArray(node->left, students, index);
        students[*index] = node->data;
        (*index)++;
        displayInOrderArray(node->right, students, index);
    }
}

// Add this function to sort students based on CGPA
void sortStudentsByCGPA(Student students[], int count)
{
    for (int i = 0; i < count - 1; ++i)
    {
        for (int j = 0; j < count - i - 1; ++j)
        {
            if (students[j].studentCGPA < students[j + 1].studentCGPA)
            {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
            else if (students[j].studentCGPA == students[j + 1].studentCGPA &&
                     students[j].rollno > students[j + 1].rollno)
            {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}



void displayInOrder(TreeNode *node)
{
    if (node != NULL)
    {
        displayInOrder(node->left);
        printf("\n%-20s%-10s%-10s%-20s%-15s%-5s\n",
               node->data.studentName, node->data.studentId,
               node->data.studentDept, node->data.studentAddress,
               node->data.studentContactNum);
        printf("%-.2f", node->data.studentCGPA);
        displayInOrder(node->right);
    }
}


void displaySortedByCGPA(TreeNode *node) {
    if (node == NULL) {
        return;
    }

    // Create an array to store students
    Student students[100]; // Assuming a maximum of 100 students
    int count = 0;

    // Store students in the array in an in-order traversal
    displayInOrderArray(node, students, &count);

    // Sort students by CGPA in descending order, and by rollno in ascending order
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (students[j].studentCGPA < students[j + 1].studentCGPA) {
                // Swap students based on CGPA
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            } else if (students[j].studentCGPA == students[j + 1].studentCGPA &&
                       students[j].rollno > students[j + 1].rollno) {
                // If CGPA is the same, sort by rollno
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    // Display the sorted students
    printf("\n\n%-20s%-10s%-10s%-20s%-15s%-5s\n", "Name", "ID", "Dept", "Address", "Contact", "CGPA");
    printf("\t\t---------------------------------------------------------------------------------------------------");

    for (int i = 0; i < count; i++) {
        printf("\n%-20s%-10s%-10s%-20s%-15s%-.2f\n", students[i].studentName, students[i].studentId,
               students[i].studentDept, students[i].studentAddress, students[i].studentContactNum, students[i].studentCGPA);
    }

    printf("\n\n\t\tPress Enter to continue...");
    getchar();
    getchar();
}

TreeNode *searchNodeByRollNo(TreeNode *node, int rollno)
{
    if (node == NULL || rollno == node->data.rollno)
    {
        return node;
    }
    if (rollno < node->data.rollno)
    {
        return searchNodeByRollNo(node->left, rollno);
    }
    return searchNodeByRollNo(node->right, rollno);
}



TreeNode *searchNode(TreeNode *node, int rollno)
{
    if (node == NULL || rollno == node->data.rollno)
    {
        return node;
    }
    if (rollno < node->data.rollno)
    {
        return searchNode(node->left, rollno);
    }
    return searchNode(node->right, rollno);
}



void updateNode(TreeNode** node, Student newData) {
    if (*node != NULL) {
        if (newData.rollno == (*node)->data.rollno) {
            (*node)->data = newData;
        } else if (newData.rollno < (*node)->data.rollno) {
            updateNode(&((*node)->left), newData);
        } else {
            updateNode(&((*node)->right), newData);
        }
    }
}


void createAccount()
{
    Student studentInformation;
    printf("\n\t\t\t====== Create Student Account ======\n");
    printf("\n\t\t\tEnter Student's Name : ");
    getchar();
    gets(studentInformation.studentName);
    printf("\t\t\tEnter Student's ID : ");
    gets(studentInformation.studentId);
    printf("\t\t\tEnter Student's Department : ");
    gets(studentInformation.studentDept);
    printf("\t\t\tEnter Student's Address : ");
    gets(studentInformation.studentAddress);
    printf("\t\t\tEnter Student's Contact Number : ");
    gets(studentInformation.studentContactNum);
    printf("\t\t\tEnter Student's Current CGPA : ");
    scanf("%f", &studentInformation.studentCGPA);
    printf("\t\t\tEnter Student's Roll Number : ");
    scanf("%d", &studentInformation.rollno);

    insertNode(&root, studentInformation);

    // Update the recentlyAddedStudent variable
    recentlyAddedStudent = studentInformation;

    printf("\n\n\t\t\tInformation has been stored successfully\n");
    printf("\n\n\t\t\tPress Enter to continue...");
    getchar();
    getchar();
}



void displayInOrderWithRollNo(TreeNode *node) {
    if (node != NULL) {
        displayInOrderWithRollNo(node->left);
        printf("%-5d%-25s%-10s%-15s%-20s%-15s%-.2f\n", node->data.rollno, node->data.studentName, node->data.studentId,
               node->data.studentDept, node->data.studentAddress, node->data.studentContactNum, node->data.studentCGPA);
        displayInOrderWithRollNo(node->right);
    }
}

void displayInfo()
{
    system("cls");
    printf("\t\t\t\t====== All Students Information ======\n");

    // Updated column widths for better alignment
    printf("%-5s%-25s%-10s%-15s%-20s%-15s%-5s\n", "Roll No", "Name", "ID", "Dept.", "Address", "Contact", "CGPA");
    printf("--------------------------------------------------------------------------------------------\n");

    displayInOrderWithRollNo(root); // Display the list of all students

    int searchRollNo;
    printf("\n\nEnter Roll No to search (0 to return to the main menu): ");
    scanf("%d", &searchRollNo);

    if (searchRollNo != 0) {
        searchStudent(root, searchRollNo); // Call the searchStudent function to find and display a specific student
    }

    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}

// Modified displayInOrder function to include Roll No






int isRollNoUnique(TreeNode *node, int rollno)
{
    if (node == NULL)
    {
        return 1; // Roll number is unique if tree is empty
    }

    if (rollno == node->data.rollno)
    {
        return 0; // Roll number already exists
    }

    if (rollno < node->data.rollno)
    {
        return isRollNoUnique(node->left, rollno);
    }

    return isRollNoUnique(node->right, rollno);
}
void updateInfo() {
    system("cls");
    printf("\t\t\t\t====== Update Student Information ======\n");

    int tempRollNo;
    printf("\n\t\t\tEnter Student's Roll No to update: ");
    scanf("%d", &tempRollNo);

    // Search for the student by roll number
    TreeNode *foundNode = searchNodeByRollNo(root, tempRollNo);

    if (foundNode != NULL) {
        Student updatedData;

        // Input the updated information
        printf("\n\t\t\tEnter updated Student's Name (press Enter to keep it unchanged): ");
        getchar();
        gets(updatedData.studentName);
        if (strlen(updatedData.studentName) == 0) {
            strcpy(updatedData.studentName, foundNode->data.studentName);
        }

        printf("\t\t\tEnter updated Student's ID (press Enter to keep it unchanged): ");
        gets(updatedData.studentId);
        if (strlen(updatedData.studentId) == 0) {
            strcpy(updatedData.studentId, foundNode->data.studentId);
        }

        printf("\t\t\tEnter updated Student's Department (press Enter to keep it unchanged): ");
        gets(updatedData.studentDept);
        if (strlen(updatedData.studentDept) == 0) {
            strcpy(updatedData.studentDept, foundNode->data.studentDept);
        }

        printf("\t\t\tEnter updated Student's Address (press Enter to keep it unchanged): ");
        gets(updatedData.studentAddress);
        if (strlen(updatedData.studentAddress) == 0) {
            strcpy(updatedData.studentAddress, foundNode->data.studentAddress);
        }

        printf("\t\t\tEnter updated Student's Contact Number (press Enter to keep it unchanged): ");
        gets(updatedData.studentContactNum);
        if (strlen(updatedData.studentContactNum) == 0) {
            strcpy(updatedData.studentContactNum, foundNode->data.studentContactNum);
        }

        printf("\t\t\tEnter updated Student's Current CGPA (press Enter to keep it unchanged): ");
        char cgpaInput[10];
        gets(cgpaInput);
        if (strlen(cgpaInput) == 0) {
            updatedData.studentCGPA = foundNode->data.studentCGPA;
        } else {
            sscanf(cgpaInput, "%f", &updatedData.studentCGPA);
        }

        // Keep the roll number unchanged
        updatedData.rollno = tempRollNo;

        // Update the student information
        updateNode(&foundNode, updatedData);

        printf("\n\n\t\t\tInformation updated successfully!\n");
    } else {
        printf("\n\t\t\tRoll No not found.\n");
    }

    printf("\n\n\t\tPress Enter to continue...");
    getchar();
    getchar();
}






void deleteAccount(TreeNode **node, int rollno)
{
    if (*node == NULL)
    {
        printf("\n\t\t\tStudent with Roll No not found.\n");
        return;
    }

    if (rollno < (*node)->data.rollno)
    {
        deleteAccount(&((*node)->left), rollno);
    }
    else if (rollno > (*node)->data.rollno)
    {
        deleteAccount(&((*node)->right), rollno);
    }
    else
    {
        // Node with the roll number found, now delete it
        TreeNode *temp;
        if ((*node)->left == NULL)
        {
            temp = *node;
            *node = (*node)->right;
            free(temp);
        }
        else if ((*node)->right == NULL)
        {
            temp = *node;
            *node = (*node)->left;
            free(temp);
        }
        else
        {
            // Node has two children, find the in-order successor
            TreeNode *minNode = (*node)->right;
            while (minNode->left != NULL)
            {
                minNode = minNode->left;
            }
            (*node)->data = minNode->data;
            deleteAccount(&((*node)->right), minNode->data.rollno);
        }
        printf("\n\t\t\tStudent account deleted successfully.\n");
    }
}

// Function to check if a given roll number is unique in the tree


// Function to search for a student by student ID and print the information


void searchStudent(TreeNode *node, int rollno)
{
    TreeNode *foundNode = searchNodeByRollNo(node, rollno);
    if (foundNode != NULL)
    {
        printf("\n\t\t\t====== Student Information ======\n");
        printf("\n\t\t\tRoll No: %d", foundNode->data.rollno);
        printf("\n\t\t\tName: %s", foundNode->data.studentName);
        printf("\n\t\t\tID: %s", foundNode->data.studentId);
        printf("\n\t\t\tDepartment: %s", foundNode->data.studentDept);
        printf("\n\t\t\tAddress: %s", foundNode->data.studentAddress);
        printf("\n\t\t\tContact Number: %s", foundNode->data.studentContactNum);
        printf("\n\t\t\tCGPA: %.2f", foundNode->data.studentCGPA);
    }
    else
    {
        printf("\n\t\t\tStudent with Roll No not found.\n");
    }

    printf("\n\n\t\t\tPress Enter to continue...");
    getchar();
    getchar();
}


void displayRecentlyAddedStudent()
{
    printf("\n\t\t\t====== Recently Added Student Information ======\n");
    printf("\n\t\t\tRoll No: %d", recentlyAddedStudent.rollno);
    printf("\n\t\t\tName: %s", recentlyAddedStudent.studentName);
    printf("\n\t\t\tID: %s", recentlyAddedStudent.studentId);
    printf("\n\t\t\tDepartment: %s", recentlyAddedStudent.studentDept);
    printf("\n\t\t\tAddress: %s", recentlyAddedStudent.studentAddress);
    printf("\n\t\t\tContact Number: %s", recentlyAddedStudent.studentContactNum);
    printf("\n\t\t\tCGPA: %.2f", recentlyAddedStudent.studentCGPA);

    printf("\n\n\t\t\tPress Enter to continue...");
    getchar();
    getchar();
}


// Add this function to count students
int countStudents(TreeNode *node) {
    if (node == NULL) {
        return 0;
    }
    return 1 + countStudents(node->left) + countStudents(node->right);
}


int main() {
    char option;

    while (option != '0') {
        printf("\t\t====== Student Management Database System ======\n");
        printf("\n\t\t\t1. Create Student Account");
        printf("\n\t\t\t2. Display All Students Information");
        printf("\n\t\t\t3. Update Student Information");
        printf("\n\t\t\t4. Display Students Sorted by CGPA");
        printf("\n\t\t\t5. Search Student by Roll No");
        printf("\n\t\t\t6. Delete Student by Roll No");
        printf("\n\t\t\t7. Display Recently Added Student");
        printf("\n\t\t\t8. Count Students"); // Option to count students
        printf("\n\t\t\t0. Exit");

        printf("\n\n\n\t\t\tEnter Your Option: ");
        scanf(" %c", &option);

        switch (option) {
            case '1':
                createAccount();
                break;
            case '2':
                displayInfo();
                break;
            case '3':
                updateInfo();
                break;
            case '4':
                displaySortedByCGPA(root);
                break;
            case '5':
                printf("\n\t\t\tEnter Student's Roll No to search: ");
                int searchRollNo;
                scanf("%d", &searchRollNo);
                searchStudent(root, searchRollNo);
                break;
            case '6':
                printf("\n\t\t\tEnter Student's Roll No to delete: ");
                int deleteRollNo;
                scanf("%d", &deleteRollNo);
                deleteAccount(&root, deleteRollNo);
                break;
            case '7':
                displayRecentlyAddedStudent();
                break;
            case '8':
                // Call the countStudents function and display the count
                int studentCount = countStudents(root);
                printf("\n\t\t\tTotal Students in the Database: %d\n", studentCount);
                break;
            case '0':
                printf("\n\t\t\t====== Thank You ======");
                break;
            default:
                printf("\n\t\t\tInvalid Option, Please Enter the Correct Option!\n");
        }

        printf("\n\n\t\tPress Enter to continue...");
        getchar();
        getchar();
    }

    return 0;
}


