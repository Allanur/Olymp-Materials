var
   n:longint;
function name(n:longint):boolean;
var
   n1,n2,s1,s2,i:integer;
begin
   n1:=n div 1000;
   n2:=n mod 1000;
   s1:=0;
   s2:=0;
   for i:=1 to 3 do
   begin
      s1:=s1+n1 mod 10;
      s2:=s2+n2 mod 10;
      n1:=n1 div 10;
      n2:=n2 div 10;
   end;
   if s1=s2 then
      name:=true
   else
      name:=false;
end;
begin
   readln (n);
   if ((name(n+1)) or (name(n-1))) and (n<>999999)then
      writeln ('Yes')
   else
      writeln ('No');
end.
