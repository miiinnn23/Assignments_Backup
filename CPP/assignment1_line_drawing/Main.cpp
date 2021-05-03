#include "MyShapes.h"
#include <cstdlib>

int main(int argc, char const *argv[])
{
 
  Canvas canvas(40, 20);
  Shape * shape[30];
  char str[100];
  char c;
  int x, y, a, b, count = 0;

  while(count < 30) {

    cout << "> ";
    gets(str);
    sscanf(str, "%c %d %d %d %d", &c, &x, &y, &a, &b);

    if(c == 'l') {
      Line line(x, y, a, b);

      line.draw(canvas);
      shape[count] = &line;
      canvas.print();
    }

    else if(c == 'r') {
      Rect rect(x, y, a, b);

      rect.draw(canvas);
      shape[count] = &rect;
      canvas.print();
    }

    else if(c == 'v') {
      VLine vline(x, y, a);

      vline.draw(canvas);
      shape[count] = &vline;
      canvas.print();
    }

    else if(c == 'h') {
      HLine hline(x, y, a);

      hline.draw(canvas);
      shape[count] = &hline;
      canvas.print();
    }

    else if(c == 's') {
      Square square(x, y, a);

      square.draw(canvas);
      shape[count] = &square;
      canvas.print();
    }

    else if(c == 'q') {
      break;
    }

    else {
      continue;
    }
    count += 1;
    
  }
  

  /**
   * [입력 방식]
   * Line : l x1 y1 x2 y2<엔터>       ==> 예) l 10 10 20 20<엔터>
   * Rect : r x y width height<엔터>  ==> 예) r 10 20 40 20<엔터>
   * VLine : v x y length<엔터>       ==> 예) v 10 20 5<엔터>
   * HLine : h x y length<엔터>       ==> 예) v 10 20 5<엔터>
   * Square : s x y length<엔터>      ==> 예) s 10 20 5<엔터>
   * 종료 : q<엔터>
   **/
  return 0;
}