program PL0B;
var n, x;
procedure prime;
var m; 
begin  
   m := x div 2;
   while x <> (x div m) * m do
      m := m - 1;
end;
begin
   n = 3;
   while 1 < n do
   begin
      x := n;
      prime;
      n := n - 1
   end
end.
