#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>  
#include<cmath>
#define InvalidValueException -1
using namespace std; 
/*题目要求：编写一个程序，计算出15000mb某种原油彻底裂化可以产生多少原料*/
class oil{
	private:
	int TypeInInt;
	string TypeInString;
	double HeavyOilAmount;
	double LightOilAmount;
	double NaphthaAmount;
	double GasAmount;
	
	public:
	void GetOilTypeAndAmount(int type){//获取原油是那种，1是BC原油，2是GT轻油，3是GT原油，4是GT重油，5是GT极重油 
		switch(type){
			case 1:
				TypeInInt=1;
				TypeInString="BCOil";
				HeavyOilAmount=4500;
				LightOilAmount=15000;
				NaphthaAmount=6000;
				GasAmount=18000;
	            break;
		    case 2:
		    	TypeInInt=2;
		    	TypeInString="GTLightOil";
				HeavyOilAmount=1000;
				LightOilAmount=2000;
				NaphthaAmount=3000;
				GasAmount=24000;
		    	break;
		    case 3:
		    	TypeInInt=3;
		    	TypeInString="GTOil";
				HeavyOilAmount=1500;
				LightOilAmount=7500;
				NaphthaAmount=22500;
				GasAmount=9000;		    
				break;
		    case 4:
			    TypeInInt=4;
			    TypeInString="GTHeavyOil";
			    HeavyOilAmount=37500;
				LightOilAmount=6750;
				NaphthaAmount=2250;
				GasAmount=9000;
			    break;
			case 5:
			    TypeInInt=5;
			    TypeInString="GTExtraHeavyOil";
			    HeavyOilAmount=56250;
				LightOilAmount=10125;
				NaphthaAmount=3375;
				GasAmount=13500;
			    break;
			default:
			    break; 	
	   }
    }
    
    void OutPutData(){//输出数据用来检验 
    	cout<<"原油类型号："<<this->TypeInInt<<endl;
    	cout<<"原油类型："<<this->TypeInString<<endl;
    	printf("产出重燃油总量：%lf，产出轻燃油总量：%lf，产出石脑油总量：%lf，产出炼油气总量：%lf\n",this->HeavyOilAmount,this->LightOilAmount,this->NaphthaAmount,this->GasAmount);
	}
    double GetHeavyOilAmount(){
    	return this->HeavyOilAmount;
	}
	double GetLightOilAmount(){
		return this->LightOilAmount;
	}
	double GetNaphthaAmount(){
		return this->NaphthaAmount;
	}
	double GetGasAmount(){
		return this->GasAmount;
	}
	void Initialization(){
		this->GasAmount=0;
		this->HeavyOilAmount=0;
		this->NaphthaAmount=0;
		this->LightOilAmount=0;
		this->TypeInInt=-1;
		this->TypeInString="";
	}
};
class All{
	private:
	double HeavyOilAmount;
	double LightOilAmount;
	double NaphthaAmount;
	double GasAmount;
	int GetFuel;//为0时，不生产高十六，为1时，生产柴油，为2时，生产高十六 
	int HeavyOilCrackedType;//重燃油裂化方式
	// 0：直接蒸馏 1：轻度氢气 2：中度氢气 3：重度氢气 4：轻度蒸汽 5：中度蒸汽 6：重度蒸汽 
	int LightOilCrackedType;//轻燃油裂化方式 
	// 1：轻度氢气 2：中度氢气 3：重度氢气 4：轻度蒸汽 5：中度蒸汽 6：重度蒸汽 	
	int NaphthaCrackedType;//石脑油裂化方式 
	// 1：轻度氢气 2：中度氢气 3：重度氢气 4：轻度蒸汽 5：中度蒸汽 6：重度蒸汽 	
	int GasCrackedType;//炼油气裂化方式 
	// 0：直接蒸馏 1：轻度氢气 2：中度氢气 3：重度氢气 4：轻度蒸汽 5：中度蒸汽 6：重度蒸汽 	
	
	//定义嵌套类Product用来存储产物
	public:
	class Product{
         friend class All;
		 private:
		 double methane;//甲烷 
		 double ethane;//乙烷 
		 double propane;//丙烷 
		 double butane;//丁烷 
         double octane;
		 double helium;//氦气
		 double toluene;//甲苯
		 double benzene;//苯
		 double vinyl;//乙烯
		 double acrylic;//丙烯
		 double butene;//丁烯
		 double butadiene;//丁二烯 
		 double phenol;//苯酚 
		 double TinyCarbonDust;//小撮碳粉	
		 double Fuel;//柴油 
		 double CetaneBoostedDiesel;//高十六 
		 public:
		 void Initialization(){
		 	this->methane=0;
		 	this->ethane=0;
		 	this->propane=0;
		 	this->butane=0;
			this->helium=0;
			this->toluene=0;
			this->benzene=0;
			this->vinyl=0;
			this->acrylic=0;
			this->butene=0;
			this->butadiene=0;
			this->TinyCarbonDust=0; 
			this->phenol=0;
            this->octane=0;
            this->Fuel=0;
            this->CetaneBoostedDiesel=0;
		 }
		 void OutPutInformation(){//输出内部内容 
		 	//cout<<"甲烷产量："<<this->methane<<endl;
		 	printf("甲烷产量：%lf\n",this->methane/(double)15); 
		 	//cout<<"乙烷产量："<<this->ethane<<endl;
		 	printf("乙烷产量：%lf\n",this->ethane/(double)15); 
			//cout<<"丙烷产量："<<this->propane<<endl;
		 	printf("丙烷产量：%lf\n",this->propane/(double)15); 
			//cout<<"丁烷产量："<<this->butane<<endl; 
		 	printf("丁烷产量：%lf\n",this->butane/(double)15); 
			//cout<<"氦气产量："<<this->helium<<endl;
            printf("辛烷产量：%lf\n",this->octane/(double)15);
		 	printf("氦气产量：%lf\n",this->helium/(double)15); 
			//cout<<"甲苯产量："<<this->toluene<<endl;
		 	printf("甲苯产量：%lf\n",this->toluene/(double)15); 
			//cout<<"苯产量："<<this->benzene<<endl;
		 	printf("苯产量：%lf\n",this->benzene/(double)15); 
			//cout<<"乙烯产量："<<this->vinyl<<endl;
		 	printf("乙烯产量：%lf\n",this->vinyl/(double)15); 
			//cout<<"丙烯产量："<<this->acrylic<<endl;
		 	printf("丙烯产量：%lf\n",this->acrylic/(double)15); 
			//cout<<"丁烯产量："<<this->butene<<endl;
		 	printf("丁烯产量：%lf\n",this->butene/(double)15); 
			//cout<<"丁二烯产量："<<this->butadiene<<endl;
		 	printf("丁二烯产量：%lf\n",this->butadiene/(double)15); 
			//cout<<"小撮碳粉产量："<<this->TinyCarbonDust<<endl;
			printf("苯酚产量：%lf\n",this->phenol/(double)15);
		 	printf("小撮碳粉产量：%lf\n",TinyCarbonDust/(double)15);  
		 	printf("柴油产量：%lf\n",this->Fuel/(double)15); 
		 	printf("高十六产量：%lf\n",this->CetaneBoostedDiesel/(double)15);
		 } 
		 void MethaneAdd(double num){
		 	this->methane=this->methane+num;
		 }
		 double GetMethaneAmount(){
		 	return this->methane;
		 }
		 void EthaneAdd(double num){
		 	this->ethane=this->ethane+num;
		 }	
		 double GetEthaneAmount(){
		 	return this->ethane;
		 }
		 void PropaneAdd(double num){
		 	this->propane=this->propane+num;
		 }
		 double GetPropaneAmount(){
		 	return this->propane;
		 }
		 void ButaneAdd(double num){
		 	this->butane=this->butane+num;
		 }
		 double GetButaneAmount(){
		 	return this->butane;
		 }
		 void HeliumAdd(double num){
		 	this->helium=this->helium+num;
		 }
		 double GetHeliumAmount(){
		 	return this->helium;
		 }
		 void TolueneAdd(double num){
		 	this->toluene=this->toluene+num;
		 }
		 double GetTolueneAmount(){
		 	return this->toluene; 
		 }
		 void BenezeAdd(double num){
		 	this->benzene=this->benzene+num;
		 }
		 double GetBenezeAmount(){
		 	return this->benzene;
		 }
		 void VinylAdd(double num){
		 	this->vinyl=this->vinyl+num;
		 }
		 double GetVinylAmount(){
		 	return this->vinyl;
		 }
		 void AcrylicAdd(double num){
		 	this->acrylic=this->acrylic+num; 
		 }
		 double GetAcrylicAmount(){
		 	return this->acrylic;
		 }
		 void ButeneAdd(double num){
		 	this->butene=this->butene+num;
		 }
		 double GetButeneAmount(){
		 	return this->butene;
		 }
		 void ButadieneAdd(double num){
		 	this->butadiene=this->butadiene+num;
		 }
		 double GetButadieneAmount(){
		 	return this->butadiene;
		 }
		 void TinyCarbonDustAdd(double num){
		 	this->TinyCarbonDust=this->TinyCarbonDust+num;
		 }
		 double GetTinyCarbonDustAmount(){
		 	return this->TinyCarbonDust;
		 }
	     void PhenolAdd(double num){
	     	this->phenol=this->phenol+num;
		 }
		 double GetPhenolAmount(){
		 	return this->phenol;
		 }
         void OctaneAdd(double num){
            this->octane=this->octane+num;
         }
         double GetOctaneAmount(){
         	return this->octane;
		 }
         void FuelAdd(double num){
         	this->Fuel=this->Fuel+num;
		 }	
		 double GetFuelAmount(){
		 	return this->Fuel;
		 }
		 void CetaneBoostedDieselAdd(double num){
		 	this->CetaneBoostedDiesel=this->CetaneBoostedDiesel+num;
		 } 
		 double GetCetaneBoostedDieselAmount(){
		 	return this->CetaneBoostedDiesel;
		 }
	};
	
	public:
	Product Products;
	void HeavyOilCrack(){//裂化后蒸馏重燃油 
		 switch(this->HeavyOilCrackedType){
		 	case 0://直接蒸馏重燃油 
		 		Products.BenezeAdd(0.4*this->HeavyOilAmount);
		 		Products.TolueneAdd(0.4*this->HeavyOilAmount);
		 		Products.PhenolAdd(0.25*this->HeavyOilAmount);
                this->HeavyOilAmount=0;
		 		break;
		 	case 1://轻度氢气裂化重燃油 
                Products.MethaneAdd(0.075*this->HeavyOilAmount);
                Products.EthaneAdd(0.075*this->HeavyOilAmount);
                Products.PropaneAdd(0.1*this->HeavyOilAmount);
                Products.ButaneAdd(0.1*this->HeavyOilAmount);
                this->LightOilAmount=this->LightOilAmount+this->HeavyOilAmount*0.6;
                this->NaphthaAmount=this->NaphthaAmount+0.1*this->HeavyOilAmount;
                this->HeavyOilAmount=0;
		 		break;
		 	case 2://中度氢气裂化重燃油
                Products.MethaneAdd(0.1*this->HeavyOilAmount);
                Products.EthaneAdd(0.1*this->HeavyOilAmount);
                Products.PropaneAdd(0.15*this->HeavyOilAmount);
                Products.ButaneAdd(0.15*this->HeavyOilAmount);
                this->LightOilAmount=this->LightOilAmount+this->HeavyOilAmount*0.4;
                this->NaphthaAmount=this->NaphthaAmount+0.4*this->HeavyOilAmount;
                this->HeavyOilAmount=0;               
		 		break;
		 	case 3://重度氢气裂化重燃油
                Products.MethaneAdd(0.175*this->HeavyOilAmount);
                Products.EthaneAdd(0.175*this->HeavyOilAmount);
                Products.PropaneAdd(0.3*this->HeavyOilAmount);
                Products.ButaneAdd(0.3*this->HeavyOilAmount);
                this->LightOilAmount=this->LightOilAmount+this->HeavyOilAmount*0.2;
                this->NaphthaAmount=this->NaphthaAmount+0.25*this->HeavyOilAmount;
                this->HeavyOilAmount=0;        
		 		break;
		 	case 4://轻度蒸汽裂化重燃油
                Products.TolueneAdd(0.025*this->HeavyOilAmount);
                Products.BenezeAdd(0.125*this->HeavyOilAmount);
                Products.ButeneAdd(0.025*this->HeavyOilAmount);
                Products.ButadieneAdd(0.015*this->HeavyOilAmount);
                Products.PropaneAdd(0.003*this->HeavyOilAmount);
                Products.AcrylicAdd(0.03*this->HeavyOilAmount);
                Products.EthaneAdd(0.005*this->HeavyOilAmount);
                Products.VinylAdd(0.05*this->HeavyOilAmount);
                Products.MethaneAdd(0.05*this->HeavyOilAmount);
                Products.TinyCarbonDustAdd(0.001*this->HeavyOilAmount);
                this->LightOilAmount=this->LightOilAmount+this->HeavyOilAmount*0.3;
                this->NaphthaAmount=this->NaphthaAmount+0.05*this->HeavyOilAmount;
                this->HeavyOilAmount=0;
		 		break;
		 	case 5://中度蒸汽裂化重燃油
                Products.TolueneAdd(0.04*this->HeavyOilAmount);
                Products.BenezeAdd(0.2*this->HeavyOilAmount);
                Products.ButeneAdd(0.04*this->HeavyOilAmount);
                Products.ButadieneAdd(0.025*this->HeavyOilAmount);
                Products.PropaneAdd(0.005*this->HeavyOilAmount);
                Products.AcrylicAdd(0.05*this->HeavyOilAmount);
                Products.EthaneAdd(0.007*this->HeavyOilAmount);
                Products.VinylAdd(0.075*this->HeavyOilAmount);
                Products.MethaneAdd(0.075*this->HeavyOilAmount);
                Products.TinyCarbonDustAdd(0.002*this->HeavyOilAmount);
                this->LightOilAmount=this->LightOilAmount+this->HeavyOilAmount*0.2;
                this->NaphthaAmount=this->NaphthaAmount+0.2*this->HeavyOilAmount;
                this->HeavyOilAmount=0;
		 		break;
		 	case 6://重度蒸汽裂化重燃油
                Products.TolueneAdd(0.08*this->HeavyOilAmount);
                Products.BenezeAdd(0.4*this->HeavyOilAmount);
                Products.ButeneAdd(0.08*this->HeavyOilAmount);
                Products.ButadieneAdd(0.05*this->HeavyOilAmount);
                Products.PropaneAdd(0.01*this->HeavyOilAmount);
                Products.AcrylicAdd(0.1*this->HeavyOilAmount);
                Products.EthaneAdd(0.015*this->HeavyOilAmount);
                Products.VinylAdd(0.15*this->HeavyOilAmount);
                Products.MethaneAdd(0.15*this->HeavyOilAmount);
                Products.TinyCarbonDustAdd(0.003*this->HeavyOilAmount);
                this->LightOilAmount=this->LightOilAmount+this->HeavyOilAmount*0.1;
                this->NaphthaAmount=this->NaphthaAmount+0.125*this->HeavyOilAmount;
                this->HeavyOilAmount=0;
		 		break;
		 	case -1://不裂化 
			    break; 
		 } 
	}
	void LightOilCrack(){//裂化后蒸馏轻燃油 
		switch(this->LightOilCrackedType){
            case 1://轻度氢气裂化轻燃油
                Products.OctaneAdd(0.1*this->LightOilAmount);
                Products.ButaneAdd(0.15*this->LightOilAmount);
                Products.PropaneAdd(0.2*this->LightOilAmount);
                Products.EthaneAdd(0.125*this->LightOilAmount);
                Products.MethaneAdd(0.125*this->LightOilAmount);
                this->NaphthaAmount=this->NaphthaAmount+0.8*this->LightOilAmount;
                this->LightOilAmount=0;
                break;
            case 2://中度氢气裂化轻燃油
                Products.OctaneAdd(0.05*this->LightOilAmount);
                Products.ButaneAdd(0.2*this->LightOilAmount);
                Products.PropaneAdd(1.1*this->LightOilAmount);
                Products.EthaneAdd(0.4*this->LightOilAmount);
                Products.MethaneAdd(0.4*this->LightOilAmount);
                this->NaphthaAmount=this->NaphthaAmount+0.5*this->LightOilAmount;
                this->LightOilAmount=0;
                break;                
            case 3://重度氢气裂化轻燃油
                Products.OctaneAdd(0.02*this->LightOilAmount);
                Products.ButaneAdd(0.125*this->LightOilAmount);
                Products.PropaneAdd(0.125*this->LightOilAmount);
                Products.EthaneAdd(1.5*this->LightOilAmount);
                Products.MethaneAdd(1.5*this->LightOilAmount);
                this->NaphthaAmount=this->NaphthaAmount+0.2*this->LightOilAmount;
                this->LightOilAmount=0;
                break;
            case 4://轻度蒸汽裂化轻燃油
                Products.TolueneAdd(0.04*this->LightOilAmount);
                Products.BenezeAdd(0.2*this->LightOilAmount);
                Products.ButeneAdd(0.075*this->LightOilAmount);
                Products.ButadieneAdd(0.06*this->LightOilAmount);
                Products.PropaneAdd(0.02*this->LightOilAmount);
                Products.AcrylicAdd(0.15*this->LightOilAmount);
                Products.EthaneAdd(0.01*this->LightOilAmount);
                Products.VinylAdd(0.05*this->LightOilAmount);
                Products.MethaneAdd(0.05*this->LightOilAmount);
                Products.TinyCarbonDustAdd(0.001*this->LightOilAmount);
                this->HeavyOilAmount=this->HeavyOilAmount+0.15*this->LightOilAmount;
                this->NaphthaAmount=this->NaphthaAmount+0.4*this->LightOilAmount;
                this->LightOilAmount=0;
		 		break;                
            case 5://中度蒸汽裂化轻燃油
                Products.TolueneAdd(0.05*this->LightOilAmount);
                Products.BenezeAdd(0.3*this->LightOilAmount);
                Products.ButeneAdd(0.09*this->LightOilAmount);
                Products.ButadieneAdd(0.075*this->LightOilAmount);
                Products.PropaneAdd(0.035*this->LightOilAmount);
                Products.AcrylicAdd(0.2*this->LightOilAmount);
                Products.EthaneAdd(0.03*this->LightOilAmount);
                Products.VinylAdd(0.15*this->LightOilAmount);
                Products.MethaneAdd(0.15*this->LightOilAmount);
                Products.TinyCarbonDustAdd(0.002*this->LightOilAmount);
                this->HeavyOilAmount=this->HeavyOilAmount+0.1*this->LightOilAmount;
                this->NaphthaAmount=this->NaphthaAmount+0.25*this->LightOilAmount;
                this->LightOilAmount=0;
		 		break;              
            case 6://重度蒸汽裂化轻燃油
                Products.TolueneAdd(0.03*this->LightOilAmount);
                Products.BenezeAdd(0.15*this->LightOilAmount);
                Products.ButeneAdd(0.065*this->LightOilAmount);
                Products.ButadieneAdd(0.05*this->LightOilAmount);
                Products.PropaneAdd(0.05*this->LightOilAmount);
                Products.AcrylicAdd(0.25*this->LightOilAmount);
                Products.EthaneAdd(0.05*this->LightOilAmount);
                Products.VinylAdd(0.25*this->LightOilAmount);
                Products.MethaneAdd(0.25*this->LightOilAmount);
                Products.TinyCarbonDustAdd(0.003*this->LightOilAmount);
                this->HeavyOilAmount=this->HeavyOilAmount+0.05*this->LightOilAmount;
                this->NaphthaAmount=this->NaphthaAmount+0.1*this->LightOilAmount;
                this->LightOilAmount=0;
		 		break; 
		 	case -1:
		 		break;
        }
	}
	void NaphthaCrack(){//裂化后蒸馏石脑油 
		switch(this->NaphthaCrackedType){
            case 1://轻度氢气裂化石脑油
                Products.ButaneAdd(0.8*this->NaphthaAmount);
                Products.PropaneAdd(0.3*this->NaphthaAmount);
                Products.EthaneAdd(0.25*this->NaphthaAmount);
                Products.MethaneAdd(0.25*this->NaphthaAmount);
                this->NaphthaAmount=0;
                break;
            case 2://中度氢气裂化石脑油
                Products.ButaneAdd(0.2*this->NaphthaAmount);
                Products.PropaneAdd(1.1*this->NaphthaAmount);
                Products.EthaneAdd(0.4*this->NaphthaAmount);
                Products.MethaneAdd(0.4*this->NaphthaAmount);
                this->NaphthaAmount=0;
                break;
            case 3://重度氢气裂化石脑油
                Products.ButaneAdd(0.125*this->NaphthaAmount);
                Products.PropaneAdd(0.125*this->NaphthaAmount);
                Products.EthaneAdd(1.5*this->NaphthaAmount);
                Products.MethaneAdd(1.5*this->NaphthaAmount);
                this->NaphthaAmount=0;
                break;
            case 4://轻度蒸汽裂化石脑油
                Products.TolueneAdd(0.04*this->NaphthaAmount);
                Products.BenezeAdd(0.15*this->NaphthaAmount);
                Products.ButeneAdd(0.08*this->NaphthaAmount);
                Products.ButadieneAdd(0.15*this->NaphthaAmount);
                Products.PropaneAdd(0.015*this->NaphthaAmount);
                Products.AcrylicAdd(0.2*this->NaphthaAmount);
                Products.EthaneAdd(0.035*this->NaphthaAmount);
                Products.VinylAdd(0.2*this->NaphthaAmount);
                Products.MethaneAdd(0.2*this->NaphthaAmount);
                Products.TinyCarbonDustAdd(0.001*this->NaphthaAmount);
                this->LightOilAmount=this->LightOilAmount+this->NaphthaAmount*0.15;
                this->HeavyOilAmount=this->HeavyOilAmount+0.075*this->NaphthaAmount;
                this->NaphthaAmount=0;
		 		break;  
            case 5://中度蒸汽裂化石脑油
                Products.TolueneAdd(0.03*this->NaphthaAmount);
                Products.BenezeAdd(0.125*this->NaphthaAmount);
                Products.ButeneAdd(0.065*this->NaphthaAmount);
                Products.ButadieneAdd(0.1*this->NaphthaAmount);
                Products.PropaneAdd(0.03*this->NaphthaAmount);
                Products.AcrylicAdd(0.4*this->NaphthaAmount);
                Products.EthaneAdd(0.05*this->NaphthaAmount);
                Products.VinylAdd(0.35*this->NaphthaAmount);
                Products.MethaneAdd(0.35*this->NaphthaAmount);
                Products.TinyCarbonDustAdd(0.002*this->NaphthaAmount);
                this->LightOilAmount=this->LightOilAmount+this->NaphthaAmount*0.1;
                this->HeavyOilAmount=this->HeavyOilAmount+0.05*this->NaphthaAmount;
                this->NaphthaAmount=0;
		 		break;
            case 6://重度蒸汽裂化石脑油
                Products.TolueneAdd(0.02*this->NaphthaAmount);
                Products.BenezeAdd(0.1*this->NaphthaAmount);
                Products.ButeneAdd(0.05*this->NaphthaAmount);
                Products.ButadieneAdd(0.05*this->NaphthaAmount);
                Products.PropaneAdd(0.015*this->NaphthaAmount);
                Products.AcrylicAdd(0.3*this->NaphthaAmount);
                Products.EthaneAdd(0.065*this->NaphthaAmount);
                Products.VinylAdd(0.5*this->NaphthaAmount);
                Products.MethaneAdd(0.5*this->NaphthaAmount);
                Products.TinyCarbonDustAdd(0.003*this->NaphthaAmount);
                this->LightOilAmount=this->LightOilAmount+this->NaphthaAmount*0.05;
                this->HeavyOilAmount=this->HeavyOilAmount+0.025*this->NaphthaAmount;
                this->NaphthaAmount=0;
		 		break;
		 	case -1:
		 		break;
        }
	}
    void GasCrack(){//裂化后蒸馏炼油气
        switch(this->GasCrackedType){
            case 0:
                Products.ButaneAdd(0.06*this->GasAmount);
                Products.PropaneAdd(0.07*this->GasAmount);
                Products.EthaneAdd(0.1*this->GasAmount);
                Products.MethaneAdd(0.75*this->GasAmount);
                Products.HeliumAdd(0.02*this->GasAmount);
                this->GasAmount=0; 
                break;
            case 1:
                Products.HeliumAdd(0.1*this->GasAmount);
                Products.MethaneAdd(1.3*this->GasAmount);
                this->GasAmount=0; 
                break;
            case 2:
                Products.HeliumAdd(0.15*this->GasAmount);
                Products.MethaneAdd(1.4*this->GasAmount);
                this->GasAmount=0; 
                break;
            case 3:               
                Products.HeliumAdd(0.2*this->GasAmount);
                Products.MethaneAdd(1.5*this->GasAmount);
                this->GasAmount=0; 
                break;
            case 4:
                Products.HeliumAdd(0.05*this->GasAmount);
                Products.MethaneAdd(0.5*this->GasAmount);
                Products.VinylAdd(0.1*this->GasAmount);
                Products.EthaneAdd(0.01*this->GasAmount);
                Products.AcrylicAdd(0.05*this->GasAmount);
                Products.TinyCarbonDustAdd(0.001*this->GasAmount);
                this->GasAmount=0;
                break;
            case 5:
                Products.HeliumAdd(0.07*this->GasAmount);
                Products.MethaneAdd(0.6*this->GasAmount);
                Products.VinylAdd(0.2*this->GasAmount);
                Products.EthaneAdd(0.05*this->GasAmount);
                Products.AcrylicAdd(0.01*this->GasAmount);
                Products.TinyCarbonDustAdd(0.001*this->GasAmount);
                this->GasAmount=0;
                break;
            case 6:
                Products.HeliumAdd(0.01*this->GasAmount);
                Products.MethaneAdd(0.7*this->GasAmount);
                Products.VinylAdd(0.3*this->GasAmount);
                Products.EthaneAdd(0.01*this->GasAmount);
                Products.AcrylicAdd(0.01*this->GasAmount);
                Products.TinyCarbonDustAdd(0.001*this->GasAmount);
                this->GasAmount=0;
                break;
            case -1:
			    break; 
        } 
    }
	void Initialization(){//初始化数据 
		HeavyOilAmount=0;
		LightOilAmount=0;
		NaphthaAmount=0;
		GasAmount=0;
		HeavyOilCrackedType=-1;
		LightOilCrackedType=-1;
		NaphthaCrackedType=-1;
		GasCrackedType=-1;
		this->Products.Initialization();
		GetFuel=0; 
	}
	void GetCrackedType(int H,int L,int N,int G){//获取裂化的方式 
		HeavyOilCrackedType=H;
		LightOilCrackedType=L;
		NaphthaCrackedType=N; 
		GasCrackedType=G;
	}
	void ReceivedData(oil Oil){//从oil类中获取油的数目 
		this->NaphthaAmount=Oil.GetNaphthaAmount();
		this->HeavyOilAmount=Oil.GetHeavyOilAmount();
		this->GasAmount=Oil.GetGasAmount();
		this->LightOilAmount=Oil.GetLightOilAmount(); 
	}
	void OutputData(){//输出内部数据信息 
		printf("重燃油量：%lf，轻燃油量：%lf，石脑油量：%lf，炼油气量：%lf\n",this->HeavyOilAmount,this->LightOilAmount,this->NaphthaAmount,this->GasAmount);
		this->Products.OutPutInformation();
	}
	void Crack(){
		while((this->HeavyOilAmount>1e-7&&this->HeavyOilCrackedType!=-1)||(this->LightOilAmount>1e-7&&this->LightOilCrackedType!=-1)||(this->NaphthaAmount>1e-7&&this->NaphthaCrackedType!=-1)||(this->GasAmount>1e-7&&this->GasCrackedType!=-1)){
			this->HeavyOilCrack();
			this->LightOilCrack();
			this->NaphthaCrack();
			this->GasCrack();
			//printf("%lf %lf %lf %lf\n",this->HeavyOilAmount,this->LightOilAmount,this->NaphthaAmount,this->GasAmount);
		}
	}
	void MakeFuel(){
		if(this->GetFuel==1||this->GetFuel==2){
			if(this->LightOilAmount>=5*this->HeavyOilAmount){
				this->LightOilAmount=this->LightOilAmount-5*this->HeavyOilAmount;
				Products.FuelAdd(this->HeavyOilAmount*6);
				this->HeavyOilAmount=0;
			}else if(this->LightOilAmount<5*this->HeavyOilAmount){
				this->HeavyOilAmount=this->HeavyOilAmount-this->LightOilAmount/5;
				Products.FuelAdd(this->LightOilAmount*1.2);
				this->LightOilAmount=0;
			}
		}else if(this->GetFuel==0){
			//donothing;
		}
	}
	void IfGetFuel(int c){
		this->GetFuel=c;
	}	
	void MakeCetaneBoostedDiesel(){
		if(this->GetFuel==2){
			//先判断乙烯够不够用，如果不够用，不合成高十六
			if(Products.vinyl>=0.01*Products.Fuel){//乙烯过量
                Products.vinyl=Products.vinyl-Products.Fuel/(double)100;
                Products.CetaneBoostedDiesel=Products.Fuel;
                Products.Fuel=0;
            }else if(Products.vinyl<0.01*Products.Fuel){
                Products.CetaneBoostedDiesel=Products.vinyl*100;
                Products.Fuel=Products.Fuel-100*Products.vinyl;
                Products.vinyl=0;
            }
		}else{
			//donothing
		}
	}
	double GetHeavyOil(){
		return this->HeavyOilAmount;
	}
	double GetLightOil(){
		return this->LightOilAmount;
	}
	double GetNaphtha(){
		return this->NaphthaAmount;
	}
	double GetGas(){
		return this->GasAmount;
	}
    double GetProductAcrylic(){
    	return this->Products.GetAcrylicAmount();
	}
	double GetProductBeneze(){
		return this->Products.GetBenezeAmount();
	}
	double GetProductButadiene(){
		return this->Products.GetButadieneAmount();
	}
	double GetProductButane(){
		return this->Products.GetButaneAmount(); 
	}
	double GetProductButene(){
		return this->Products.GetButeneAmount();
	} 
	double GetProductCetaneBoostedDiesel(){
		return this->Products.GetCetaneBoostedDieselAmount();
	}
	double GetProductEthane(){
	    return this->Products.GetEthaneAmount();
	}
	double GetProductFuel(){
		return this->Products.GetFuelAmount();
	}
	double GetProductHelium(){
		return this->Products.GetHeliumAmount();
	}
	double GetProductMethane(){
		return this->Products.GetMethaneAmount();
	}
	double GetProductOctane(){
		return this->Products.GetOctaneAmount();
	}
	double GetProductPhenol(){
		return this->Products.GetPhenolAmount();
	}
	double GetProductPropane(){
		return this->Products.GetPropaneAmount();
	}
	double GetProductTinyCarbonDust(){
		return this->Products.GetTinyCarbonDustAmount();
	}
	double GetProductToluene(){
		return this->Products.GetTolueneAmount();
	}
	double GetProductVinyl(){
		return this->Products.GetVinylAmount();
	}
}; 
class Outputs{
	public:
	int OilType;
	//double HeavyOilAmount;
	//double LightOilAmount;
	//double NaphthaAmount;
	//double GasAmount;
	int HeavyOilCrackedType;
	int LightOilCrackedType;
	int NaphthaCrackedType;
	int GasCrackedType;
	double methane;//甲烷 
	double ethane;//乙烷 
	double propane;//丙烷 
	double butane;//丁烷 
    double octane;//辛烷 
	double helium;//氦气
	double toluene;//甲苯
	double benzene;//苯
	double vinyl;//乙烯
	double acrylic;//丙烯
	double butene;//丁烯
	double butadiene;//丁二烯 
	double phenol;//苯酚 
	double TinyCarbonDust;//小撮碳粉	
	double Fuel;//柴油 
    double CetaneBoostedDiesel;//高十六 
    void OutputData(){
	switch(this->OilType){
		case 1:cout<<"BC原油"<<endl;break;
		case 2:cout<<"GT轻油"<<endl;break;
		case 3:cout<<"GT原油"<<endl;break;
		case 4:cout<<"GT重油"<<endl;break;	 
		case 5:cout<<"GT极重油"<<endl;break;
	}
	switch(this->HeavyOilCrackedType){
		case 0:cout<<"重燃油直接蒸馏"<<endl;break;
		case 1:cout<<"重燃油轻氢裂化"<<endl;break;
		case 2:cout<<"重燃油中氢裂化"<<endl;break;
		case 3:cout<<"重燃油重氢裂化"<<endl;break;
		case 4:cout<<"重燃油轻蒸裂化"<<endl;break;
		case 5:cout<<"重燃油中蒸裂化"<<endl;break;
		case 6:cout<<"重燃油重蒸裂化"<<endl;break;
	} 
	switch(this->LightOilCrackedType){
		case 1:cout<<"轻燃油轻氢裂化"<<endl;break;
		case 2:cout<<"轻燃油中氢裂化"<<endl;break;
		case 3:cout<<"轻燃油重氢裂化"<<endl;break;
		case 4:cout<<"轻燃油轻蒸裂化"<<endl;break;
		case 5:cout<<"轻燃油中蒸裂化"<<endl;break;
		case 6:cout<<"轻燃油重蒸裂化"<<endl;break;		
	}
	switch(this->NaphthaCrackedType){
		case 1:cout<<"石脑油轻氢裂化"<<endl;break;
		case 2:cout<<"石脑油中氢裂化"<<endl;break;
		case 3:cout<<"石脑油重氢裂化"<<endl;break;
		case 4:cout<<"石脑油轻蒸裂化"<<endl;break;
		case 5:cout<<"石脑油中蒸裂化"<<endl;break;
		case 6:cout<<"石脑油重蒸裂化"<<endl;break;			
	}
	switch(this->GasCrackedType){
		case 0:cout<<"炼油气直接蒸馏"<<endl;break;
		case 1:cout<<"炼油气轻氢裂化"<<endl;break;
		case 2:cout<<"炼油气中氢裂化"<<endl;break;
		case 3:cout<<"炼油气重氢裂化"<<endl;break;
		case 4:cout<<"炼油气轻蒸裂化"<<endl;break;
		case 5:cout<<"炼油气中蒸裂化"<<endl;break;
		case 6:cout<<"炼油气重蒸裂化"<<endl;break;		
	}
	
	
	printf("甲烷产量：%lf\n",this->methane/double(15)); 
	printf("乙烷产量：%lf\n",this->ethane/double(15)); 
	printf("丙烷产量：%lf\n",this->propane/double(15)); 
	printf("丁烷产量：%lf\n",this->butane/double(15)); 
    printf("辛烷产量：%lf\n",this->octane/double(15));
	printf("氦气产量：%lf\n",this->helium/double(15)); 
	printf("甲苯产量：%lf\n",this->toluene/double(15)); 
	printf("苯产量：%lf\n",this->benzene/double(15)); 
	printf("乙烯产量：%lf\n",this->vinyl/double(15)); 
	printf("丙烯产量：%lf\n",this->acrylic/double(15)); 
	printf("丁烯产量：%lf\n",this->butene/double(15)); 
	printf("丁二烯产量：%lf\n",this->butadiene/double(15));
	printf("苯酚产量：%lf\n",this->phenol/double(15));
	printf("小撮碳粉产量：%lf\n",this->TinyCarbonDust/double(15));  
	printf("柴油产量：%lf\n",this->Fuel/double(15)); 
	printf("高十六产量：%lf\n",this->CetaneBoostedDiesel/double(15));    	
	}
};

int MethaneCompare(const void *a ,const void *b) { 
    return (*(Outputs*)b).methane-(*(Outputs*)a).methane; 
}
int EthaneCompare(const void *a,const void *b){
	return (*(Outputs*)b).ethane-(*(Outputs*)a).ethane;
} 
int PropaneCompare(const void *a,const void *b){
	return (*(Outputs*)b).propane-(*(Outputs*)a).propane;
}
int ButaneCompare(const void *a,const void *b){
	return (*(Outputs*)b).butane-(*(Outputs*)a).butane;
}
int OctaneCompare(const void *a,const void *b){
	return (*(Outputs*)b).octane-(*(Outputs*)a).octane;
}
int HeliumCompare(const void *a,const void *b){
	return (*(Outputs*)b).helium-(*(Outputs*)a).helium;
}
int BenzeneCompare(const void *a,const void *b){
	return (*(Outputs*)b).benzene-(*(Outputs*)a).benzene;
}
int TolueneCompare(const void *a,const void *b){
	return (*(Outputs*)b).toluene-(*(Outputs*)a).toluene;	
}
int VinylCompare(const void *a,const void *b){
	return (*(Outputs*)b).vinyl-(*(Outputs*)a).vinyl;
}
int AcrylicCompare(const void *a,const void *b){
	return (*(Outputs*)b).acrylic-(*(Outputs*)a).acrylic;
}
int ButeneCompare(const void *a,const void *b){
	return (*(Outputs*)b).butene-(*(Outputs*)a).butene;
} 
int ButadieneCompare(const void *a,const void *b){
	return (*(Outputs*)b).butadiene-(*(Outputs*)a).butadiene;
}
int PhenolCompare(const void *a,const void *b){
	return (*(Outputs*)b).phenol-(*(Outputs*)a).phenol;
}
int TinyCarbonDustCompare(const void *a,const void *b){
	return (*(Outputs*)b).TinyCarbonDust-(*(Outputs*)a).TinyCarbonDust;
}
int FuelCompare(const void *a,const void *b){
	return (*(Outputs*)b).Fuel-(*(Outputs*)a).Fuel;
}
int CetaneBoostedDieselCompare(const void *a,const void *b){
	return (*(Outputs*)b).CetaneBoostedDiesel-(*(Outputs*)a).CetaneBoostedDiesel;
}
int main(){
	Outputs OutPutData[1764];
	int MakeFuel=0;
	cout<<"是否考虑制作柴油，若考虑则输入1，否则输入0"<<endl;
	scanf("%d",&MakeFuel);
	int cnt=0;
	oil Oil;
	All Calc;
    for(int a=1;a<=5;a++){
    	cnt=0;
    	for(int b=0;b<=6;b++){
    		for(int c=1;c<=6;c++){
    			for(int d=1;d<=6;d++){
    				for(int e=0;e<=6;e++){
    					Oil.Initialization();
    					Oil.GetOilTypeAndAmount(a);
    					Calc.Initialization();
    					Calc.ReceivedData(Oil);
    					Calc.GetCrackedType(b,c,d,e);
    					Calc.IfGetFuel(MakeFuel);
    					Calc.MakeFuel();
    					Calc.Crack();
    					//Calc.OutputData();
    					OutPutData[cnt].OilType=a;
    					//OutPutData[cnt].HeavyOilAmount=Calc.GetHeavyOil();
    					//OutPutData[cnt].LightOilAmount=Calc.GetLightOil();
    					//OutPutData[cnt].NaphthaAmount=Calc.GetNaphtha();
    					//OutPutData[cnt].GasAmount=Calc.GetGas();
    					OutPutData[cnt].HeavyOilCrackedType=b;
    					OutPutData[cnt].LightOilCrackedType=c;
    					OutPutData[cnt].NaphthaCrackedType=d;
    					OutPutData[cnt].GasCrackedType=e;
    					OutPutData[cnt].methane=Calc.GetProductMethane();
    					OutPutData[cnt].ethane=Calc.GetProductEthane();
    					OutPutData[cnt].propane=Calc.GetProductPropane();
    					OutPutData[cnt].butane=Calc.GetProductButane();
    					OutPutData[cnt].octane=Calc.GetProductOctane();
                        OutPutData[cnt].helium=Calc.GetProductHelium();//氦气
	                    OutPutData[cnt].toluene=Calc.GetProductToluene();//甲苯
	                    OutPutData[cnt].benzene=Calc.GetProductBeneze();//苯
	                    OutPutData[cnt].vinyl=Calc.GetProductVinyl();//乙烯
	                    OutPutData[cnt].acrylic=Calc.GetProductAcrylic();//丙烯
	                    OutPutData[cnt].butene=Calc.GetProductButene();//丁烯
	                    OutPutData[cnt].butadiene=Calc.GetProductButadiene();//丁二烯 
	                    OutPutData[cnt].phenol=Calc.GetProductPhenol();//苯酚 
	                    OutPutData[cnt].TinyCarbonDust=Calc.GetProductTinyCarbonDust();//小撮碳粉	
	                    OutPutData[cnt].Fuel=Calc.GetProductFuel();//柴油 
                        OutPutData[cnt].CetaneBoostedDiesel=Calc.GetProductCetaneBoostedDiesel();
                        //OutputStruct(OutPutData[cnt]);
                        //return 0;
    					cnt++;
					}
				}
			}
		}
		qsort(OutPutData,1764,sizeof(Outputs),MethaneCompare);
		printf("原油情况为%d时，最大输出的甲烷及所用裂解方式为：\n",a);
		OutPutData[0].OutputData(); 
		qsort(OutPutData,1764,sizeof(Outputs),EthaneCompare);
		printf("原油情况为%d时，最大输出的乙烷及所用裂解方式为：\n",a);
		OutPutData[0].OutputData(); 
		qsort(OutPutData,1764,sizeof(Outputs),PropaneCompare);
		printf("原油情况为%d时，最大输出的丙烷及所用裂解方式为：\n",a);
		OutPutData[0].OutputData(); 
		qsort(OutPutData,1764,sizeof(Outputs),ButaneCompare);
		printf("原油情况为%d时，最大输出的丁烷及所用裂解方式为：\n",a);
		OutPutData[0].OutputData(); 
		qsort(OutPutData,1764,sizeof(Outputs),OctaneCompare);
		printf("原油情况为%d时，最大输出的辛烷及所用裂解方式为：\n",a);
		OutPutData[0].OutputData(); 
		qsort(OutPutData,1764,sizeof(Outputs),HeliumCompare);
		printf("原油情况为%d时，最大输出的氦气及所用裂解方式为：\n",a);
		OutPutData[0].OutputData(); 
		qsort(OutPutData,1764,sizeof(Outputs),TolueneCompare);
		printf("原油情况为%d时，最大输出的甲苯及所用裂解方式为：\n",a);
		OutPutData[0].OutputData(); 
		qsort(OutPutData,1764,sizeof(Outputs),BenzeneCompare);
		printf("原油情况为%d时，最大输出的苯及所用裂解方式为：\n",a);
		OutPutData[0].OutputData(); 
		qsort(OutPutData,1764,sizeof(Outputs),VinylCompare);
		printf("原油情况为%d时，最大输出的乙烯及所用裂解方式为：\n",a);
		OutPutData[0].OutputData(); 
		qsort(OutPutData,1764,sizeof(Outputs),AcrylicCompare);
		printf("原油情况为%d时，最大输出的丙烯及所用裂解方式为：\n",a);
		OutPutData[0].OutputData(); 
		qsort(OutPutData,1764,sizeof(Outputs),ButeneCompare);
		printf("原油情况为%d时，最大输出的丁烯及所用裂解方式为：\n",a);
		OutPutData[0].OutputData(); 
		qsort(OutPutData,1764,sizeof(Outputs),ButadieneCompare);
		printf("原油情况为%d时，最大输出的丁二烯及所用裂解方式为：\n",a);
		OutPutData[0].OutputData(); 
		qsort(OutPutData,1764,sizeof(Outputs),PhenolCompare);
		printf("原油情况为%d时，最大输出的苯酚及所用裂解方式为：\n",a);
		OutPutData[0].OutputData(); 
		 
	}
    return 0;

}
