#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string inputBlock(int size, int status){

    string inputBlock;

    if (status == 0 or status == size){
        /// inputBlock block for status = 0 ///
        for (int i=0; i<size; i++){
            inputBlock += '0';
        }

        return inputBlock;
    } else {
        /// inputBlock block for status != 0 ///
        int mid = (size%2 == 0) ? (size-1)/2 : size/2;
        for (int i=0; i<size; i++){
            if (i<=mid){
                inputBlock += '0';
            } else {
                inputBlock += '1';
            }
        }

        return inputBlock;
    }
}

string buildInput(int* status, int* quantity, int* length){

    string input;

    for (int i=0; i<length[0]; i++){
        input += inputBlock(quantity[i], status[i]);
    }

    return input;

}

void processBlock(int status, int quantity, string input, string response, int* statusResult, int* quantityResult, int inputIndex, int responseIndex){
    if (status == quantity or quantity == 1){
        statusResult[0] = status;
        quantityResult[0] = quantity;
        statusResult[1] = 0;
        quantityResult[1] = 0; 
    } else {
        int mid = (quantity%2 == 0) ? quantity/2 : (quantity+1)/2;
        *quantityResult = mid;
        *(quantityResult+1) = quantity-mid;

        int sum = 0;
        for (int i=inputIndex; i<(inputIndex+quantity); i++){
            if (input[i] == '1'){
                sum++;
            }
        }

        for (int i=responseIndex; i<(responseIndex+quantity-status); i++){
            if (response[i] == '1'){
                sum--;
            }
        }

        statusResult[1] = sum;
        statusResult[0] = status - sum;
    }
}

void processResponse(int* status, int* quantity, string input, string response, int *length, int N){

    int dupStatus[N];
    int dupQuantity[N];
    int indexInput = 0;
    int indexResponse = 0;
    int indexDuplicate = 0;
    for (int i=0; i<length[0]; i++){
        int resultStatus[2];
        int resultQuantity[2];
        processBlock(status[i], quantity[i], input, response, resultStatus, resultQuantity, indexInput, indexResponse);
        indexInput += quantity[i];
        indexResponse += quantity[i]-status[i];

        dupStatus[indexDuplicate] = resultStatus[0];
        dupQuantity[indexDuplicate] = resultQuantity[0];
        indexDuplicate += 1;

        if (resultQuantity[1] != 0){
            dupStatus[indexDuplicate] = resultStatus[1];
            dupQuantity[indexDuplicate] = resultQuantity[1];
            indexDuplicate += 1;
        }
    }

    for (int i=0; i<indexDuplicate; i++){
        status[i] = dupStatus[i];
        quantity[i] = dupQuantity[i];
    }

    length[0] = indexDuplicate;
}

void showBroken(int* status, int* quantity, int* length, int* broken){

    int index = 0;
    int indexB = 0;
    for (int i=0; i<length[0]; i++){

        if (status[i] != 0){
            int qty = quantity[i];
            for (int j=0; j<qty; j++){
                broken[indexB] = index+j;
                indexB++;
            }
        }
        index += quantity[i];
    }

}


int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int T;
    cin >> T;

    for (int t=0; t<T; t++){
        int N, B, F;
        scanf("%i %i %i", &N, &B, &F);


        int status[N];
        status[0] = B;
        int quantity[N];
        quantity[0] = N;
        int l = 1;
        int* length = &l;
        int trial = 0;
        int sumInput = 0;
        while (trial < F){
            trial++;
            bool loopStatus = true;
            string input;
            input = buildInput(status, quantity, length);
            sumInput = 0;
            for (int i=0; i<N; i++){
                if (input[i] == '1'){
                    sumInput++;
                }
            }
            if (sumInput == 0){
                // cout << 0 << endl;
                int broken[B];
                showBroken(status, quantity, length, broken);
        
                for (int i=0; i<B; i++){
                    cout << broken[i] << " \n"[i+1==B];
                }
        
                cout << flush;
                int judgement;
                cin >> judgement;
        
                if (judgement == 1){
                    // cout << "tes" << endl;
                    loopStatus = false;
                } else {
                    exit(1);
                }
            } else {
                cout << input << endl;
                cout << flush;
                string response;
                cin >> response;
                processResponse(status, quantity, input, response, length, N);
            }

            if (loopStatus == false){
                break;
            }

        }
    }

    return 0;
}