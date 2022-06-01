using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;

namespace MovieBase
{
    public partial class Country
    {
        public Country()
        {
            Productions = new HashSet<Production>();
        }

        public int Id { get; set; }

        [Display(Name = "Назва країни")]
        public string Name { get; set; } = null!;
        [Display(Name = "Кіностудії")]

        public virtual ICollection<Production> Productions { get; set; }
    }
}
