  function f=dog2d(N,K,sigma)
  % N is grid size, sigma speaks for itself , k=is the change factor in
  % both the guassian
 [x y]=meshgrid(round(-N/2):round(N/2), round(-N/2):round(N/2));
 f=exp(-x.^2/(2*sigma^2)-y.^2/(2*sigma^2))+exp(-x.^2/(2*K^2*sigma^2)-...
   y.^2/(2*K^2*sigma^2));
 f=f./sum(f(:));