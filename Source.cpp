// Krypto Program by Alex Zahabizadeh

#include<iostream>
#include<string>
#include<fstream>


using namespace std;


int operationDecider(int, int);
void processor(int[10], ofstream&, int);
int calcOp(int, int, int);



int main()
{
    ofstream file;

    file.open("Lister.txt");
	int numbers[5];
	int answer;

	cout << "Welcome to Krypto Lister!" << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << "Enter number " << i + 1 << ": ";
		cin >> numbers[i];
		cout << endl;
	}

	cout << "Answer: ";
	cin >> answer;
	cout << endl;

	int algo[9];

	//random numbers into numbers[]

	for (int i = 0; i < 5; i++)
	{
		algo[0] = numbers[i];

		for (int i2 = 0; i2 < 5; i2++)
		{
			if (!(i2 == i))
			{
				algo[1] = numbers[i2];

				for (int i3 = 0; i3 < 5; i3++)
				{
					if (!(i3 == i || i3 == i2))
					{
						for (int i4 = 0; i4 < 5; i4++)
						{
							if (!(i4 == i3 || i4 == i2 || i4 == i))
							{
								for (int i5 = 0; i5 < 5; i5++)
								{
									if (!(i5 == i4 || i5 == i3 || i5 == i2 || i5 == i))
									{
										for (int a1 = 0; a1 < 5; a1++)
										{
											int location = 2;

											algo[location] = operationDecider(a1, numbers[i3]);

											if (algo[location] != numbers[i3])
											{
												location++;
												algo[location] = numbers[i3];
											}

											location++;

											for (int a2 = 0; a2 < 5; a2++)
											{
												int location2 = location;

												algo[location2] = operationDecider(a2, numbers[i4]);

												if (algo[location2] != numbers[i4])
												{
													location2++;
													algo[location2] = numbers[i4];
												}

												location2++;

												for (int a3 = 0; a3 < 5; a3++)
												{
													int location3 = location2;

													algo[location3] = operationDecider(a3, numbers[i5]);

													if (algo[location3] != numbers[i5])
													{
														location3++;
														algo[location3] = numbers[i5];
													}

													location3++;

													if (location < 9)
													{
														for (int a4 = 0; a4 < 4; a4++)
														{
															int location4 = location3;
															algo[location4] = operationDecider(a4, 0);

															location4++;

															if (location4 < 9)
															{
																for (int a5 = 0; a5 < 4; a5++)
																{
																	algo[location4] = operationDecider(a5, 0);
																	processor(algo, file, answer);
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	file.close();

}


int operationDecider(int orderOp, int nextNum)
{
	int next;

	if (orderOp == 0)
		next = '+';
	else if (orderOp == 1)
		next = '-';
	else if (orderOp == 2)
		next = 'x';
	else if (orderOp == 3)
		next = '/';
	else if (orderOp == 4)
		next = nextNum;

	return next;
}


void processor(int final[9], ofstream& file, int theAnswer)
{
	int calcing[9];

	for (int i = 0; i < 9; i++)
    {
        calcing[i] = final[i];
    }

	for (int testing = 0; testing < 9; testing++)
	{
		cout << calcing[testing] << " ";
	}

	int pauser;
    //cout << endl << "Pause3: ";
  	//cin >> pauser;

    for (int a = 0; a < 4; a++)
    {
       int done = 0;
     //  cout << endl << "Next Op" << endl;
        for (int i = 1; i < 6; i++)
        {
		//	cout << "next place" << endl;

            if (done == 0)
            {
                if (calcing[i] == 43)
                {
                    calcing[i-2] = calcing[i-2] + calcing[i-1];
                    done = 1;
                }
                else if (calcing[i] == 45)
                {
                    calcing[i-2] = calcing[i-2] - calcing[i-1];
                    done = 1;
                }
                else if (calcing[i] == 47)
                {
                    calcing[i-2] = calcing[i-2] * calcing[i-1];
                    done = 1;
                }
                else if (calcing[i] == 120)
                {
                    calcing[i-2] = calcing[i-2] / calcing[i-1];
                    done = 1;
                }
                if (done == 1)
                {
                    int operatorcheck = 0;
                    int numbercheck = 0;

                    for (int i2 = 1; i2 < 7; i2++)
                    {
                        if ((i2 + 1 + numbercheck == i) && operatorcheck < 1)
                            operatorcheck++;

                        if ((i2 + 1 + operatorcheck == i - 1) && numbercheck < 1)
                            numbercheck++;

                        calcing[i2] = calcing[i2 + operatorcheck + numbercheck + 1];
                    }
                    for (int testing = 0; testing < 9; testing++)
                          {
                              cout << calcing[testing] << " ";
                          }
                            int pauser;
                           //cout << endl << "Pause1: ";
                           // cin >> pauser;
                }
            }
        }
    }




	if (calcing[0] == theAnswer)
	{
		for (int i = 0; i < 9; i++)
		{
			if (final[i] == 43 || final[i] == 45 || final[i] == 120 || final[i] == 47)
			{
				char convert = final[i];
				cout << convert << ' ';
				file << convert << ' ';
			}
			else
			{
				cout << final[i] << ' ';
				file << final[i] << ' ';
			}
		}
		cout << " = " << calcing [0] << endl;
		file << " = " << calcing [0] << endl;
	}

	int pause;
	//cout << "Pause2: ";
	//cin >> pause;
}
