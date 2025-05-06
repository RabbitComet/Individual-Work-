#include<iostream>
#include<string>

void binar(int n,std::string word = ""){

	if(word.size() == n){
		std::cout<<word<<std::endl;
		return;
	}
	
	binar(n,word+'0');

	binar(n,word+'1');
}


int main(){
	
	int n;

	std::cout<<"what is n: ";

	std::cin>>n;

	binar(n);

}
