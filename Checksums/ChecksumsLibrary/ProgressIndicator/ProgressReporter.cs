using ChecksumsLibrary.ProgressIndicator.DirectoryRepresentation;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChecksumsLibrary.ProgressIndicator
{
    public class ProgressReporter : ProcessedFileObserver
    {
        private long bytesToRead;
        private long totalBytesProcessed;
        private Stopwatch watch;

        public ProgressReporter(IAbstractFile root)
        {
            this.bytesToRead = (long)root.GetSizeInBytes();
            this.totalBytesProcessed = 0;
            this.watch = new Stopwatch();
        }

        public void handleProcessedFile(string name, long bytesProcessed)
        {
            if (watch.IsRunning == false)
            {
                watch.Start();
            }

            // message born in HashStreamWriter
            if (bytesProcessed == -1)
            {
                Console.WriteLine("Now observing file : " + name);
            }
            else // message born in the checksum classes
            {
                this.totalBytesProcessed += bytesProcessed;
                Console.WriteLine("Processed: " + bytesProcessed + " from the file: " + name);
                Console.WriteLine("Remaining: " + calcualteRemaining() + " minutes.");
            }
        }

        private string calcualteRemaining()
        {
            decimal bytesPermSecond = (decimal)this.watch.Elapsed.TotalSeconds / (decimal)this.totalBytesProcessed;
            decimal minutesRemaining = ((decimal)this.bytesToRead - (decimal)this.totalBytesProcessed) / (decimal)bytesPermSecond;
            return minutesRemaining.ToString();
        }
    }
}
