#include <stdio.h>

float sum();
float subs();
float multiply();
float divide();
float power();
float average();
float max_of_nums();

int main(){
  int operator;

  while (operator != 0){
    
    printf("\n\n\n\nWELCOME TO GTU CALCULATOR MACHINE\nSTUDENT NAME: AHMET YAŞAR GÖKSU\nPLEASE SELECT FROM THE FOLLOWING\nMENU : \n");
    printf("(1) ADD TWO NUMBERS\n"
          "(2) SUBTRACT TWO NUMBERS\n"
          "(3) MULTIPLY TWO NUMBERS\n"
          "(4) DIVIDE TWO NUMBERS\n"
          "(5) TAKE THE NTH POWER OF A NUMBER\n"
          "(6) FIND AVERAGE OF NUMBERS INPUTTED\n"
          "(7) FIND THE MAXIMUM OF NUMBERS INPUTTED\n"
          "(0) EXIT\n"
          "PLEASE SELECT: ");
    scanf("%d", &operator);
    if (operator == 1) {
      sum();
    } else if (operator == 2) {
      subs();
    } else if (operator == 3) {
      multiply();
    } else if (operator == 4) {
      divide();
    } else if (operator == 5) {
      power();
    } else if (operator == 6) {
      average();
    } else if (operator == 7) {
      max_of_nums();
    }
  }
}

float power(){
  float num1, result, is_input_ok;
  int num2;
  result = 1;
  is_input_ok = 0;
  while (!is_input_ok){
    printf("Enter first number: ");
    if (scanf("%f", &num1) != 1) {
       printf("Invalid input. Please enter an float.\n");
       while (getchar() != '\n'); 
    } else {
      break;
    }
  }

  while (!is_input_ok){
    printf("Enter the power of %.2f you want: ", num1);
    if (scanf("%d", &num2) != 1) {
       printf("Invalid input. Please enter an integer.\n");
       while (getchar() != '\n'); 
    } else {
      break;
    }
  }
  if (num2 == 0){
    printf("The %d. power of %.2f is 1\n", num2, num1);
    return 1;
  }

  
  if (num2 > 0) {
    for (int i = 0; i < num2; i++){
      result *= num1;
    }
    printf("The %d. power of %.2f is %.2f.\n", num2, num1, result);
  } else if (num2 < 0) {
      num2 *= -1;
      for (int i = 0; i < num2; i++){
        result *= num1;
    }
    result = 1 / result;
    printf("The -%d. power of %.2f is %.2f.\n", num2, num1, result);
  }

  return result;
}

float max_of_nums() {
    float max_num = 0;
    float nums;
    char input;

    printf("Please enter numbers (type 'e' or 'E' to finish):\n");

    while (1) {
        printf("Enter a number or 'e': ");

        if (scanf(" %c", &input) != 1) {
            printf("Error reading input. Try again.\n");
            continue; 
        }

        if (input == 'e' || input == 'E') {
            break;
        }

        ungetc(input, stdin);
        if (scanf("%f", &nums) == 1) {
            if (nums > max_num) {
              max_num = nums;
            }
        } else {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n'); 
        }
    }
    printf("Maximum of numbers inputted: %.2f\n", max_num);
    

}

float average() {
    int counter = 0;
    float result = 0;
    float nums;
    char input;

    printf("Please enter numbers (type 'e' or 'E' to finish):\n");

    while (1) {
        printf("Enter a number or 'e': ");

        if (scanf(" %c", &input) != 1) {
            printf("Error reading input. Try again.\n");
            continue; 
        }

        if (input == 'e' || input == 'E') {
            break;
        }

        ungetc(input, stdin);
        if (scanf("%f", &nums) == 1) {
            result += nums;
            counter++;
        } else {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n'); 
        }
    }


    if (counter > 0) {
        printf("The average of these numbers = %.2f\n" , result/counter);
        return result / counter;
    } else {
        printf("No numbers were entered. The result is 0.00.\n");
        return 0.0;
    }
}


float sum(){
  float num1, num2, result, is_input_ok;

  is_input_ok = 0;
  while (!is_input_ok){
    printf("Enter first number: ");
    if (scanf("%f", &num1) != 1) {
       printf("Invalid input. Please enter an float.\n");
       while (getchar() != '\n'); 
    } else {
      break;
    }
  }

  while (!is_input_ok){
    printf("Enter second number: ");
    if (scanf("%f", &num2) != 1) {
       printf("Invalid input. Please enter an float.\n");
       while (getchar() != '\n'); 
    } else {
      break;
    }
  }
  result = num1 + num2;
  printf("%.2f + %.2f = %.2f\n", num1, num2, result);
  return result;
}

float subs(){
  float num1, num2, result, is_input_ok;

  is_input_ok = 0;
  while (!is_input_ok){
    printf("Enter first number: ");
    if (scanf("%f", &num1) != 1) {
       printf("Invalid input. Please enter an float.\n");
       while (getchar() != '\n'); 
    } else {
      break;
    }
  }

  while (!is_input_ok){
    printf("Enter second number: ");
    if (scanf("%f", &num2) != 1) {
       printf("Invalid input. Please enter an float.\n");
       while (getchar() != '\n'); 
    } else {
      break;
    }
  }
  result = num1 - num2;
  printf("%.2f - %.2f = %.2f\n", num1, num2, result);
  return result;
}

float multiply(){
  float num1, num2, result, is_input_ok;
  is_input_ok = 0;
  while (!is_input_ok){
    printf("Enter first number: ");
    if (scanf("%f", &num1) != 1) {
       printf("Invalid input. Please enter an float.\n");
       while (getchar() != '\n'); 
    } else {
      break;
    }
  }

  while (!is_input_ok){
    printf("Enter second number: ");
    if (scanf("%f", &num2) != 1) {
       printf("Invalid input. Please enter an float.\n");
       while (getchar() != '\n'); 
    } else {
      break;
    }
  }
  result = num1 * num2;
  printf("%.2f x %.2f = %.2f\n", num1, num2, result);
  return result;
}

float divide(){
  float num1, num2, result, is_input_ok;

  is_input_ok = 0;
  while (!is_input_ok){
    printf("Enter first number: ");
    if (scanf("%f", &num1) != 1) {
       printf("Invalid input. Please enter an float.\n");
       while (getchar() != '\n'); 
    } else {
      break;
    }
  }

  while (!is_input_ok){
    printf("Enter second number: ");
    if (scanf("%f", &num2) != 1) {
       printf("Invalid input. Please enter an float.\n");
       while (getchar() != '\n'); 
    } else if (num2 == 0){
       printf("Invalid input. Second number cannot be zero!\n");
       while (getchar() != '\n'); 
    }else {
      break;
    }
  }
  result = num1 / num2;
  printf("%.2f / %.2f = %.2f\n", num1, num2, result);
  return result;
}

