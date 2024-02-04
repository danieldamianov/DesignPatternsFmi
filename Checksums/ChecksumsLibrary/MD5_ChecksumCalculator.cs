using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace ChecksumsLibrary
{
    public class MD5_ChecksumCalculator : IChecksumClaculator
    {
        public string calculate(Stream inputStream)
        {
            using (MD5 md5 = MD5.Create())
            {
                byte[] hashBytes = md5.ComputeHash(inputStream);
                return BitConverter.ToString(hashBytes).Replace("-", "").ToLower();
            }

        }
    }
}
