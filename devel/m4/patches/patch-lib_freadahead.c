--- lib/freadahead.c
+++ lib/freadahead.c
@@ -94,6 +94,12 @@
   if (fp->state == 4 /* WR */ || fp->rp >= fp->wp)
     return 0;
   return fp->wp - fp->rp;
+#elif defined __OHOS__
+  struct {
+      unsigned flags;
+      unsigned char *rpos, *rend;
+  } *f = (void *)fp;
+  return f->rend ? f->rend - f->rpos : 0;
 #elif defined SLOW_BUT_NO_HACKS     /* users can define this */
   abort ();
   return 0;
