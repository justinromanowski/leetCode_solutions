class Solution {

// solution worked up to testcase 39

public:
    int strongPasswordChecker(string password) {
        int pwStrength = 0;
        int addChange = 0;
        int delChange = 0;
        int charChange = 0;
        int repeatChange = 0;
        int repeatCounter = 0;
        bool capsChar = false;
        bool lowerChar = false;
        bool digitChar = false;

        //bypass

        //check if too short or too long
        if(password.length()<6){
            addChange+=(6-password.length());
        } else if(password.length()>20){
            delChange+=(password.length()-20);
        }
        cout << "add= " << addChange << " del=" << delChange;
        //go char by char and find upper, lower, digit, and repeating chars
        for(int i = 0; i<password.length(); i++){
            //check for repeats, cant use first two chars
            if(repeatCounter>0){repeatCounter--;}
            if(i>=2 && repeatCounter==0 && password[i]==password[i-1] && password[i]==password[i-2]){
                repeatChange+=1;
                repeatCounter = 3;
            }
            if(capsChar==false && isupper(password[i])){
                //check for caps
                capsChar=true;
                //cout << "capsChar=true\n";
            } else if(lowerChar==false && islower(password[i])){
                //check for lowercase
                lowerChar=true;
                //cout << "lowerChar=true\n";
            } else if(digitChar==false && isdigit(password[i])){
                //check for digit
                digitChar=true;
                //cout << "digitChar=true\n";
            }
        }
        //add to pwStrength if any bools are false
        if(capsChar==false){charChange++;}
        if(lowerChar==false){charChange++;}
        if(digitChar==false){charChange++;}

        cout << " repeat=" << repeatChange << " char=" << charChange << endl;
        
        //repeat can be fixed by a char change
        if(repeatChange>=charChange){
            repeatChange-=charChange;
            //charChange = 0;
        }
        //repeat can also be fixed by a add change
        if(repeatChange>=addChange){
            repeatChange-=addChange;
            //lenChange = 0;
        }
        //repeat also fixed by a del change
        if(repeatChange>=delChange){
            repeatChange-=delChange;
            //lenChange = 0;
        }
        //if missing chars can be made up for by adding chars
        if(addChange>=charChange){
            addChange-=charChange;
        }
        
        
        //sum all changes left up
        pwStrength = repeatChange + addChange + charChange + delChange;
        /*
        if(password.length()>=6 && password.length()<=20){
            if(charChange>0 && repeatChange>0){
                pwStrength+=(max(charChange,repeatChange));
            } else {
                pwStrength+=(charChange+repeatChange);
            }
        } else if (password.length()>20){
                pwStrength+=(charChange+repeatChange);
        } 
        */
        cout << "PWSTR = " << pwStrength << endl;

        return pwStrength;
    }
};