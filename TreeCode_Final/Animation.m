clear
close all
fclose('all');

filename='./Output';
outfile='Cartwheel.gif';
%%data_all=load('OutputFile.txt');
%%[m,n]=size(data_all);

figure(1);



for jj=0:10:400
   file=sprintf('%s_%04d.txt',filename,jj);
   dat=load(file);
    
   %%subplot(2,4,[1 2 5 6])
   plot3(dat(:,1),dat(:,2),dat(:,3),'.');
   hold on
%    plot3(dat(end-1,1),dat(end-1,2),dat(end-1,3),'r.','MarkerSize',25);
%    plot3(dat(end,1),dat(end,2),dat(end,3),'k.','MarkerSize',25);
   axis([-20 20 -20 20 -20 20]);
   view(45,45);
   drawnow; 
   hold off
   
   %%subplot(2,4,[3 4 7 8])
   %%plot3(dat(1:end-2,1),dat(1:end-2,2),dat(1:end-2,3),'.');
   %%hold on
   %%plot3(dat(end-1,1),dat(end-1,2),dat(end-1,3),'r.','MarkerSize',25);
   %%plot3(dat(end,1),dat(end,2),dat(end,3),'k.','MarkerSize',25);
   %%axis([-4 4 -4 4 -4 4]);
   %%view(0,90);
   %%drawnow; 
   %%hold off
   
   

   frame=getframe(1);
   im=frame2im(frame);
   [imind,cm] = rgb2ind(im,256);
   if jj == 0
          imwrite(imind,cm,outfile,'gif', 'Loopcount',inf,'DelayTime',0.02);
   else
          imwrite(imind,cm,outfile,'gif','WriteMode','append','DelayTime',0.02);
   end
   
   %%fprintf([outfilepre '.txt']);
   
   
end