import  java.util.Scanner;
public class FAN {
	public static void main(String[] args) {
		FAN F1=new FAN();
		F1.setSpeed(3);
		F1.setRadius(10);
		F1.setCloar("yellow");
		F1.setOn(true);
		F1.ToString();
		FAN F2=new FAN();
		F2.setSpeed(2);
		F2.setRadius(5);
		F2.setCloar("blue");
		F2.setOn(false);
		F2.ToString();
		
	}
	final int SLOW=1;
	final int MEDIUM=2;
	final int FAST=3;
	private int speed;
	private boolean on;
	private double radius;
	private String colar;
	
	//访问器与修改
	public void setSpeed(int newspeed) {
		speed=newspeed;
	}
	public void setOn(boolean newon){
		on=newon;
	}
	public void setRadius(double newradius) {
		radius=newradius;
	}
	public void setCloar(String newcolar) {
		colar=newcolar;
	}

	public int getSpeed() {
		return speed;
	}
	public boolean getOn() {
		return on;
	}
	public double getRedius() {
		return radius;
	}
	public String getColar() {
		return colar;
	}
	
	//默认风扇
	FAN(){
		speed=SLOW;
		on=false;
		radius=5;
		colar="blue";
	}
	
	public void ToString() {
		if(on==true)
			System.out.println(speed+" colar "+radius);
		else
			System.out.println("fan is off");
	}
	
	
}
