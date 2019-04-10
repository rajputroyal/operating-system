import java.util.*;
class Procon
{public static void main(String args[])
{List<Integer>buffer=new ArrayList<Integer>();
Thread t1=new Thread(new Prod(buffer));
Thread t2=new Thread(new Cons(buffer));
t1.start();
t2.start();
}}

class Prod implements Runnable
{
List<Integer> buffer=null;
final int limit=10;
int i=10;
Prod(List<Integer> buffer)
{this.buffer=buffer;
}
public void produce(int i)throws InterruptedException
{synchronized (buffer){
while(buffer.size()==limit)
{System.out.println("buffer is full");
buffer.wait();}
synchronized(buffer){
buffer.add(i);
Thread.sleep(100);
buffer.notify();
}
}}
public void run()
{
	while(true)
	{
try
{i++;
produce(i);
}
catch(Exception e)
{System.out.println(e);}
}
}}


class Cons implements Runnable
{
List<Integer> buffer=null;

Cons(List<Integer> buffer)
{this.buffer=buffer;}
public void consume()throws InterruptedException
{synchronized (buffer)
{
while(buffer.isEmpty())
{System.out.println("buffer is empty");
buffer.wait();}
synchronized(buffer){
buffer.remove(0);
Thread.sleep(100);
buffer.notify();
}
}}
public void run()
{while(true)
{
try
{
consume();
}
catch(Exception e)
{System.out.println(e);}}
}}