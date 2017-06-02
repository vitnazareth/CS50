#include <stdio.h>

void checkNumber(long long number);

int main(void)
{
  long long orig_num; //stores CC number

  //prompts user to input credit card number.
  //Will only exit loop if number is greater than 0
  do
  {
    printf("Enter CC number: ");
    scanf("%lld", &orig_num);
    if(orig_num<0)
    {
      printf("Invalid Number. Try again. \n");
    }

  }
  while (orig_num<0);

  checkNumber(orig_num); //runs algorithm to check CC #
}

//takes CC number in long long format.
void checkNumber(long long number)
{
  int even = 0; //to store every other number, starting from 2nd to last integer
  int odd = 0; //to store every other number, starting from last integer
  long long num = number; //copies CC number for later use
  long long result = number; //copies CC number for later use
  int sum = 0; //to store the final result.

  //Checkes every other number starting from 2nd to last integer until
  //there are no more numbers to check
  while(number!=0)
  {

    number = number/10; //erases last number from CC
    int temp = number%10; //takes current last digit and stores it in temp

    //if last digit*2 is greater than 10
    if((temp*2) >= 10)
    {
      int t = temp*2; //store number*2 in t
      temp=temp*2; //multiplies current number by 2
      temp = temp%10; //takes the last digit of multiplication
      even += temp; //adds last digit to temp
      t = t/10; //takes out last digit from t
      even+= t; //adds remaining number to even
    }
    else
    {
      temp = temp*2; //multiplies current number by 2
      even += temp; //adds it to even
    }

    number = number/10; //takes out last digit

  }

  //checks every other number starting from last digit until no more number are
  //left
  while(num!=0)
  {
    int temp = num%10; //stores last digit in temp
    num = num/10; //takes out last digit
    odd+=temp; //add current digit to temp
    num = num/10; //takes out last digit
  }

  sum = even + odd; //adds even and odd sums.

  //checks to see if numbers are divisible by 10
  if(sum%10==0)
  {
    if(result>=34e13 && result<38e13)
    {
      printf("American Express\n");
    }
    else if(result>=51e14 && result<56e14)
    {
      printf("Master Card\n");
    }
    else if((result>=4e12 && result<5e12) || (result>=4e15 && result<5e15))
    {
      printf("Visa\n");
    }
    else
    {
      printf("Valid. Unknown CC.\n");
    }
  }
  else
  {
    printf("Invalid");
  }

}
