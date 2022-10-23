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
	int GetFuel;//为0时，不生产高十六，为1时，生产高16 
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
		 double NitroFuel;//高十六 
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
            this->NitroFuel=0;
		 }
		 void OutPutInformation(){//输出内部内容 
		 	//cout<<"甲烷产量："<<this->methane<<endl;
		 	printf("甲烷产量：%lf\n",this->methane/(float)15); 
		 	//cout<<"乙烷产量："<<this->ethane<<endl;
		 	printf("乙烷产量：%lf\n",this->ethane/(float)15); 
			//cout<<"丙烷产量："<<this->propane<<endl;
		 	printf("丙烷产量：%lf\n",this->propane/(float)15); 
			//cout<<"丁烷产量："<<this->butane<<endl; 
		 	printf("丁烷产量：%lf\n",this->butane/(float)15); 
			//cout<<"氦气产量："<<this->helium<<endl;
            printf("辛烷产量：%lf\n",this->octane/(float)15);
		 	printf("氦气产量：%lf\n",this->helium/(float)15); 
			//cout<<"甲苯产量："<<this->toluene<<endl;
		 	printf("甲苯产量：%lf\n",this->toluene/(float)15); 
			//cout<<"苯产量："<<this->benzene<<endl;
		 	printf("苯产量：%lf\n",this->benzene/(float)15); 
			//cout<<"乙烯产量："<<this->vinyl<<endl;
		 	printf("乙烯产量：%lf\n",this->vinyl/(float)15); 
			//cout<<"丙烯产量："<<this->acrylic<<endl;
		 	printf("丙烯产量：%lf\n",this->acrylic/(float)15); 
			//cout<<"丁烯产量："<<this->butene<<endl;
		 	printf("丁烯产量：%lf\n",this->butene/(float)15); 
			//cout<<"丁二烯产量："<<this->butadiene<<endl;
		 	printf("丁二烯产量：%lf\n",this->butadiene/(float)15); 
			//cout<<"小撮碳粉产量："<<this->TinyCarbonDust<<endl;
			printf("苯酚产量：%lf\n",this->phenol/(float)15);
		 	printf("小撮碳粉产量：%lf\n",TinyCarbonDust/(float)15);  
		 	printf("高十六烷柴油产量：%lf\n",this->NitroFuel/(float)15); 
		 } 
		 void MethaneAdd(double num){
		 	this->methane=this->methane+num;
		 }
		 void EthaneAdd(double num){
		 	this->ethane=this->ethane+num;
		 }	
		 void PropaneAdd(double num){
		 	this->propane=this->propane+num;
		 }
		 void ButaneAdd(double num){
		 	this->butane=this->butane+num;
		 }
		 void HeliumAdd(double num){
		 	this->helium=this->helium+num;
		 }
		 void TolueneAdd(double num){
		 	this->toluene=this->toluene+num;
		 }
		 void BenezeAdd(double num){
		 	this->benzene=this->benzene+num;
		 }
		 void VinylAdd(double num){
		 	this->vinyl=this->vinyl+num;
		 }
		 void AcrylicAdd(double num){
		 	this->acrylic=this->acrylic+num; 
		 }
		 void ButeneAdd(double num){
		 	this->butene=this->butene+num;
		 }
		 void ButadieneAdd(double num){
		 	this->butadiene=this->butadiene+num;
		 }
		 void TinyCarbonDustAdd(double num){
		 	this->TinyCarbonDust=this->TinyCarbonDust+num;
		 }
	     void PhenolAdd(double num){
	     	this->phenol=this->phenol+num;
		 }
         void OctaneAdd(double num){
            this->octane=this->octane+num;
         }
         void NitroFuelAdd(double num){
         	this->NitroFuel=this->NitroFuel+num;
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
            case 1:break;
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
		}
	}
	void MakeFuel(){
		if(this->GetFuel==1){
			if(this->LightOilAmount>=5*this->HeavyOilAmount){
				this->LightOilAmount=this->LightOilAmount-5*this->HeavyOilAmount;
				Products.NitroFuelAdd(this->HeavyOilAmount*6);
				this->HeavyOilAmount=0;
			}else if(this->LightOilAmount<5*this->HeavyOilAmount){
				this->HeavyOilAmount=this->HeavyOilAmount-this->LightOilAmount/5;
				Products.NitroFuelAdd(this->LightOilAmount*1.2);
				this->LightOilAmount=0;
			}
		}else if(this->GetFuel==0){
			//donothing;
		}
	}
	void IfGetFuel(int c){
		this->GetFuel=c;
	}	
}; 
int main(){
	int judge=0; 
	oil Oil;
	All Calc;
	cout<<"此程序用于计算15000mB的各种油的石化产物情况。"<<endl;
	while(true){
		
		cout<<"输入1启动运算程序，输入0结束运算程序"<<endl;
		scanf("%d",&judge);
		if(judge==1){
		Oil.Initialization();
		int InputType=0;
		cout<<"请输入油的类别："<<endl;
		cout<<"1为BC原油，2为GT轻油，3为GT原油，4为GT重油，5为GT极重油"<<endl; 
		cout<<"输入例子："<<endl;
		cout<<"1"<<endl;
		cout<<"这个例子代表选择计算15B的BC原油的石化产物情况"<<endl; 
		try{	
			scanf("%d",&InputType);
			if(InputType<1||InputType>5){
				throw InvalidValueException;
			}
			Oil.GetOilTypeAndAmount(InputType);
			//Oil.OutPutData();
			//后期需要注释掉上面的代码 
		}catch(int Exception){
			if(Exception==InvalidValueException){
				cout<<"输入的数据不能小于0或者大于5";
				continue;
			}
		}
		Calc.Initialization();
		Calc.ReceivedData(Oil);
		//Calc.GetCrackedType(5,4,4,0);
		cout<<"请输入是否制作高十六烷柴油，如果制作，输入1，否则输入0"<<endl;
		int c;
		scanf("%d",&c);
		Calc.IfGetFuel(c);
		cout<<"请输入裂化的方式（按照重燃油-轻燃油-石脑油-炼油气 的顺序）："<<endl;
		cout<<"从1到6，分别对应轻氢，中氢，重氢，轻蒸汽，中蒸汽，重蒸汽，-1对应该产物不裂解，此外对于重燃油和炼油气，0代表直接蒸馏"<<endl;
		cout<<"输入例子："<<endl;
		cout<<"0 1 1 0"<<endl;
		cout<<"这个例子代表，重燃油和炼油气直接蒸馏，轻燃油和石脑油选择轻氢裂化"<<endl; 
		int type1,type2,type3,type4;
		try{
			scanf("%d %d %d %d",&type1,&type2,&type3,&type4);
			if(type1<-1||type1>6||type2<-1||type2>6||type3<-1||type3>6||type4<-1||type4>6||type2==0||type3==0){
				throw InvalidValueException;
			}
		}catch(int Exception){
			if(Exception==InvalidValueException){
				cout<<"输入的裂化方式有误！"<<endl;
				continue;
			}
		} 
		Calc.MakeFuel();
		Calc.GetCrackedType(type1,type2,type3,type4);
		Calc.Crack(); 
		cout<<"每1000mB该原油的彻底裂解产物和燃料产物为（单位：mB）："<<endl; 
    	Calc.OutputData();
    				
		}else if(judge==0){
				break;
		}
	}
    return 0;

}
